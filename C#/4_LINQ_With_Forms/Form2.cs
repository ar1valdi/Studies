using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab10
{
    public partial class Form2 : Form
    {
        public string selectedColumn { get; private set; }
        public Form2(string[] columnNames)
        {
            InitializeComponent();
            comboBoxColumns.Items.AddRange(columnNames);
        }
        private void buttonOK_Click(object sender, EventArgs e)
        {
            selectedColumn = comboBoxColumns.SelectedItem as string;
            DialogResult = DialogResult.OK;
            Close();
        }
    }
}
