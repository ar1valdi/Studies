namespace lab10
{
    partial class Form3
    {
        private System.ComponentModel.IContainer components = null;
        private TextBox textBoxModel;
        private TextBox textBoxYear;
        private TextBox textBoxEngineModel;
        private TextBox textBoxEngineHorsePower;
        private TextBox textBoxEngineDisplacement;
        private Button buttonOK;
        private Button buttonCancel;
        private Label labelModel;
        private Label labelYear;
        private Label labelEngineModel;
        private Label labelEngineHorsePower;
        private Label labelEngineDisplacement;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.textBoxModel = new System.Windows.Forms.TextBox();
            this.textBoxYear = new System.Windows.Forms.TextBox();
            this.textBoxEngineModel = new System.Windows.Forms.TextBox();
            this.textBoxEngineHorsePower = new System.Windows.Forms.TextBox();
            this.textBoxEngineDisplacement = new System.Windows.Forms.TextBox();
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.labelModel = new System.Windows.Forms.Label();
            this.labelYear = new System.Windows.Forms.Label();
            this.labelEngineModel = new System.Windows.Forms.Label();
            this.labelEngineHorsePower = new System.Windows.Forms.Label();
            this.labelEngineDisplacement = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxModel
            // 
            this.textBoxModel.Location = new System.Drawing.Point(150, 12);
            this.textBoxModel.Name = "textBoxModel";
            this.textBoxModel.Size = new System.Drawing.Size(200, 20);
            this.textBoxModel.TabIndex = 0;
            // 
            // textBoxYear
            // 
            this.textBoxYear.Location = new System.Drawing.Point(150, 38);
            this.textBoxYear.Name = "textBoxYear";
            this.textBoxYear.Size = new System.Drawing.Size(200, 20);
            this.textBoxYear.TabIndex = 1;
            // 
            // textBoxEngineModel
            // 
            this.textBoxEngineModel.Location = new System.Drawing.Point(150, 64);
            this.textBoxEngineModel.Name = "textBoxEngineModel";
            this.textBoxEngineModel.Size = new System.Drawing.Size(200, 20);
            this.textBoxEngineModel.TabIndex = 2;
            // 
            // textBoxEngineHorsePower
            // 
            this.textBoxEngineHorsePower.Location = new System.Drawing.Point(150, 90);
            this.textBoxEngineHorsePower.Name = "textBoxEngineHorsePower";
            this.textBoxEngineHorsePower.Size = new System.Drawing.Size(200, 20);
            this.textBoxEngineHorsePower.TabIndex = 3;
            // 
            // textBoxEngineDisplacement
            // 
            this.textBoxEngineDisplacement.Location = new System.Drawing.Point(150, 116);
            this.textBoxEngineDisplacement.Name = "textBoxEngineDisplacement";
            this.textBoxEngineDisplacement.Size = new System.Drawing.Size(200, 20);
            this.textBoxEngineDisplacement.TabIndex = 4;
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(150, 142);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(75, 23);
            this.buttonOK.TabIndex = 5;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(275, 142);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(75, 23);
            this.buttonCancel.TabIndex = 6;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // labelModel
            // 
            this.labelModel.AutoSize = true;
            this.labelModel.Location = new System.Drawing.Point(12, 15);
            this.labelModel.Name = "labelModel";
            this.labelModel.Size = new System.Drawing.Size(36, 13);
            this.labelModel.TabIndex = 7;
            this.labelModel.Text = "Model";
            // 
            // labelYear
            // 
            this.labelYear.AutoSize = true;
            this.labelYear.Location = new System.Drawing.Point(12, 41);
            this.labelYear.Name = "labelYear";
            this.labelYear.Size = new System.Drawing.Size(29, 13);
            this.labelYear.TabIndex = 8;
            this.labelYear.Text = "Year";
            // 
            // labelEngineModel
            // 
            this.labelEngineModel.AutoSize = true;
            this.labelEngineModel.Location = new System.Drawing.Point(12, 67);
            this.labelEngineModel.Name = "labelEngineModel";
            this.labelEngineModel.Size = new System.Drawing.Size(70, 13);
            this.labelEngineModel.TabIndex = 9;
            this.labelEngineModel.Text = "Engine Model";
            // 
            // labelEngineHorsePower
            // 
            this.labelEngineHorsePower.AutoSize = true;
            this.labelEngineHorsePower.Location = new System.Drawing.Point(12, 93);
            this.labelEngineHorsePower.Name = "labelEngineHorsePower";
            this.labelEngineHorsePower.Size = new System.Drawing.Size(104, 13);
            this.labelEngineHorsePower.TabIndex = 10;
            this.labelEngineHorsePower.Text = "Engine Horse Power";
            // 
            // labelEngineCapacity
            // 
            this.labelEngineDisplacement.AutoSize = true;
            this.labelEngineDisplacement.Location = new System.Drawing.Point(12, 119);
            this.labelEngineDisplacement.Name = "labelEngineDisplacement";
            this.labelEngineDisplacement.Size = new System.Drawing.Size(84, 13);
            this.labelEngineDisplacement.TabIndex = 11;
            this.labelEngineDisplacement.Text = "Engine Displacement";
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(364, 181);
            this.Controls.Add(this.labelEngineDisplacement);
            this.Controls.Add(this.labelEngineHorsePower);
            this.Controls.Add(this.labelEngineModel);
            this.Controls.Add(this.labelYear);
            this.Controls.Add(this.labelModel);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.textBoxEngineDisplacement);
            this.Controls.Add(this.textBoxEngineHorsePower);
            this.Controls.Add(this.textBoxEngineModel);
            this.Controls.Add(this.textBoxYear);
            this.Controls.Add(this.textBoxModel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form3";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Enter data";
            this.ResumeLayout(false);
            this.PerformLayout();

        }
    }
}