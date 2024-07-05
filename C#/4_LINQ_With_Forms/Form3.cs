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
    public partial class Form3 : Form
    {
        public string Model { get; private set; }
        public int Year { get; private set; }
        public string EngineModel { get; private set; }
        public double EngineHorsePower { get; private set; }
        public double EngineDisplacement { get; private set; }

        public Form3()
        {
            InitializeComponent();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            // Validate and set the properties
            if (ValidateInputs())
            {
                Model = textBoxModel.Text;
                Year = int.Parse(textBoxYear.Text);
                EngineModel = textBoxEngineModel.Text;
                EngineHorsePower = double.Parse(textBoxEngineHorsePower.Text);
                EngineDisplacement = double.Parse(textBoxEngineDisplacement.Text);

                DialogResult = DialogResult.OK;
                Close();
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
            Close();
        }

        private bool ValidateInputs()
        {
            if (string.IsNullOrWhiteSpace(textBoxModel.Text))
            {
                MessageBox.Show("Error in model name", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!int.TryParse(textBoxYear.Text, out int year))
            {
                MessageBox.Show("Error in year", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (string.IsNullOrWhiteSpace(textBoxEngineModel.Text))
            {
                MessageBox.Show("Error in engine model", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!double.TryParse(textBoxEngineHorsePower.Text, out double engineHorsePower))
            {
                MessageBox.Show("Error in horse power", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); 
                return false;
            }

            if (!double.TryParse(textBoxEngineDisplacement.Text, out double engineCapacity))
            {
                MessageBox.Show("Error in displacement", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            return true;
        }
    }
}
