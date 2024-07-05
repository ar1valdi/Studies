using lab9;
using System;
using System.Collections.Immutable;
using System.ComponentModel;
using System.Windows.Forms;

namespace lab10
{
    public partial class Form1 : Form
    {
        private SortableBindingList<Car> myCarsBindingList;
        private List<Car> myCars;
        private BindingSource bindingSource;

        public Form1()
        {
            InitializeComponent();
            InitializeData();
            SetupDataGridView();
        }

        private void InitializeData()
        {
            myCars = new List<Car>(){
                 new Car("E250", new Engine(1.8, 204, "CGI"), 2009),
                 new Car("E350", new Engine(3.5, 292, "CGI"), 2009),
                 new Car("A6", new Engine(2.5, 187, "FSI"), 2012),
                 new Car("A6", new Engine(2.8, 220, "FSI"), 2012),
                 new Car("A6", new Engine(3.0, 295, "TFSI"), 2012),
                 new Car("A6", new Engine(2.0, 175, "TDI"), 2011),
                 new Car("A6", new Engine(3.0, 309, "TDI"), 2011),
                 new Car("S6", new Engine(4.0, 414, "TFSI"), 2012),
                 new Car("S8", new Engine(4.0, 513, "TFSI"), 2012)
            };
            myCarsBindingList = new SortableBindingList<Car>(myCars);
            bindingSource = new BindingSource();
            bindingSource.DataSource = myCarsBindingList;

        }

        private void SetupDataGridView()
        {
            dataGridView1.DataSource = bindingSource;

            dataGridView1.AllowUserToAddRows = true;
            dataGridView1.AllowUserToDeleteRows = true;
            dataGridView1.EditMode = DataGridViewEditMode.EditOnEnter;

            toolStripComboBox1.MouseEnter += ComboBox_Enter;
        }

        private void Add_Click(object sender, EventArgs e)
        {
            using (var addForm = new Form3())
            {
                if (addForm.ShowDialog() == DialogResult.OK)
                {
                    string engineModel = addForm.EngineModel;
                    double engineDispl = addForm.EngineDisplacement;
                    double engineHp = addForm.EngineHorsePower;
                    string carModel = addForm.Model;
                    int carYear = addForm.Year;

                    Engine eng = new Engine(engineDispl, engineHp, engineModel);
                    myCarsBindingList.Add(new Car(carModel, eng, carYear));
                }
            }

            clearLogs();
            foreach (Car car in myCars) { addLog(car.ToString()); }
        }

        private void Remove_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow != null)
            {
                var carToRemove = (Car)dataGridView1.CurrentRow.DataBoundItem;
                myCarsBindingList.Remove(carToRemove);
            }

            clearLogs();
            foreach (Car car in myCars) { addLog(car.ToString()); }
        }

        private void Sort_Click(object sender, EventArgs e)
        {
            var columnNames = dataGridView1.Columns.Cast<DataGridViewColumn>().
                Select(col => col.DataPropertyName).ToArray();
            using (var sortForm = new Form2(columnNames))
            {
                if (sortForm.ShowDialog() == DialogResult.OK)
                {
                    var selectedColumn = sortForm.selectedColumn;
                    if (!string.IsNullOrEmpty(selectedColumn))
                    {
                        myCarsBindingList.ApplySort(selectedColumn, ListSortDirection.Ascending);
                        bindingSource.DataSource = myCarsBindingList;
                    }
                }
            }

            clearLogs();
            foreach (Car car in myCars) { addLog(car.ToString()); }
        }

        private void Zadanie_1(object sender, EventArgs e)
        {
            var elements1 = myCarsBindingList
                .Where(car => car.model == "A6")
                .GroupBy(car => car.motor.model == "TDI" ? "diesel" : "petrol")
                .Select(g => new
                {
                    engineType = g.Key,
                    avgHPPL = g.Average(car => car.motor.horsePower / car.motor.displacement)
                })
                .OrderByDescending(e => e.avgHPPL);

            var elements2 = from car in myCarsBindingList
                            where car.model == "A6"
                            let engineType = car.motor.model == "TDI" ? "diesel" : "petrol"
                            group car by engineType into carGroup
                            select new
                            {
                                engineType = carGroup.Key,
                                avgHPPL = carGroup.Average(c => c.motor.horsePower / c.motor.displacement)
                            };

            elements2 = from car in elements2
                        orderby car.avgHPPL descending
                        select car;

            addLog("Method based:");
            foreach (var el in elements1) addLog(el.engineType + ": " + el.avgHPPL);
            addLog("Query syntax:");
            foreach (var el in elements2) addLog(el.engineType + ": " + el.avgHPPL);
        }

        private void Zadanie_2(object sender, EventArgs e)
        {
            Func<Car, Car, int> arg1 = HorsePowerComp;
            Predicate<Car> arg2 = IsTDI;
            Action<Car> arg3 = ShowInMsgBox;

            myCars.Sort(new Comparison<Car>(arg1));
            myCars.FindAll(arg2).ForEach(arg3);
            myCarsBindingList = new SortableBindingList<Car>(myCars);
            bindingSource.DataSource = myCarsBindingList;
        }
        private void Zadanie_3(object sender, EventArgs e)
        {
            myCarsBindingList.ApplySort("year", ListSortDirection.Ascending);
            bindingSource.DataSource = myCarsBindingList;

            addLog(myCarsBindingList[myCarsBindingList.Find("model", "A6")].ToString());
        }

        private void OnFindClick(object sender, EventArgs e)
        {
            string query = textBox2.Text;
            textBox2.Clear();
            BindingList<Car> newList = new BindingList<Car>();

            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                bool rowContainsPhrase = row.Cells
                    .Cast<DataGridViewCell>()
                    .Any(cell => cell.Value != null && cell.Value.ToString()
                    .Contains(query));


                row.Height = rowContainsPhrase ? 30 : 0;
            }
        }

        private int HorsePowerComp(Car car1, Car car2)
        {
            return -car1.motor.horsePower.CompareTo(car2.motor.horsePower);
        }

        private bool IsTDI(Car c)
        {
            if (c == null) return false;
            return c.motor.model.Equals("TDI");
        }

        private void ShowInMsgBox(Car c)
        {
            MessageBox.Show(c.ToString(), "Car Info");
        }

        private void ComboBox_Enter(object sender, EventArgs e)
        {
            var comboBox = sender as ToolStripComboBox;
            if (comboBox != null)
            {
                comboBox.Items.Clear();
                foreach (DataGridViewColumn column in dataGridView1.Columns)
                {
                    if (column.ValueType == typeof(string) || column.ValueType == typeof(Int32))
                    {
                        comboBox.Items.Add(column.HeaderText);
                    }
                }
            }
        }

        private void FindToolStrip(object sender, EventArgs e)
        {
            int id = myCarsBindingList.Find(toolStripComboBox1.Text, toolStripTextBox1.Text);
            try
            {
                MessageBox.Show(myCarsBindingList[id].ToString());
            } catch (Exception ex)
            {
                MessageBox.Show("Can't find value");
            }
        }
    }
}