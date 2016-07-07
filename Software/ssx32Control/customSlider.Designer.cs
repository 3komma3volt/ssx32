namespace ssx32Control
{
    partial class customSlider
    {
        /// <summary> 
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Komponenten-Designer generierter Code

        /// <summary> 
        /// Erforderliche Methode für die Designerunterstützung. 
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.trackPosition = new System.Windows.Forms.TrackBar();
            this.numPosition = new System.Windows.Forms.NumericUpDown();
            this.numChannel = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.numRamp = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.numTime = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.trackPosition)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numPosition)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numChannel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numRamp)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numTime)).BeginInit();
            this.SuspendLayout();
            // 
            // trackPosition
            // 
            this.trackPosition.Location = new System.Drawing.Point(8, 60);
            this.trackPosition.Maximum = 2500;
            this.trackPosition.Minimum = 500;
            this.trackPosition.Name = "trackPosition";
            this.trackPosition.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trackPosition.Size = new System.Drawing.Size(45, 138);
            this.trackPosition.TabIndex = 1;
            this.trackPosition.TickFrequency = 250;
            this.trackPosition.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.trackPosition.Value = 1250;
            this.trackPosition.ValueChanged += new System.EventHandler(this.trackPosition_ValueChanged);
            // 
            // numPosition
            // 
            this.numPosition.Location = new System.Drawing.Point(7, 204);
            this.numPosition.Maximum = new decimal(new int[] {
            2500,
            0,
            0,
            0});
            this.numPosition.Minimum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            this.numPosition.Name = "numPosition";
            this.numPosition.Size = new System.Drawing.Size(46, 20);
            this.numPosition.TabIndex = 2;
            this.numPosition.Value = new decimal(new int[] {
            1250,
            0,
            0,
            0});
            this.numPosition.ValueChanged += new System.EventHandler(this.numPosition_ValueChanged);
            // 
            // numChannel
            // 
            this.numChannel.Location = new System.Drawing.Point(10, 21);
            this.numChannel.Name = "numChannel";
            this.numChannel.Size = new System.Drawing.Size(41, 20);
            this.numChannel.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Channel:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Position:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(11, 227);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Speed:";
            // 
            // numRamp
            // 
            this.numRamp.Location = new System.Drawing.Point(10, 243);
            this.numRamp.Name = "numRamp";
            this.numRamp.Size = new System.Drawing.Size(41, 20);
            this.numRamp.TabIndex = 6;
            this.numRamp.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Enabled = false;
            this.label4.Location = new System.Drawing.Point(11, 266);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(33, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Time:";
            // 
            // numTime
            // 
            this.numTime.Enabled = false;
            this.numTime.Location = new System.Drawing.Point(10, 282);
            this.numTime.Name = "numTime";
            this.numTime.Size = new System.Drawing.Size(41, 20);
            this.numTime.TabIndex = 9;
            // 
            // customSlider
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.label4);
            this.Controls.Add(this.numTime);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.numRamp);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numChannel);
            this.Controls.Add(this.numPosition);
            this.Controls.Add(this.trackPosition);
            this.Name = "customSlider";
            this.Size = new System.Drawing.Size(61, 307);
            this.Load += new System.EventHandler(this.customSlider_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackPosition)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numPosition)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numChannel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numRamp)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numTime)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TrackBar trackPosition;
        private System.Windows.Forms.NumericUpDown numPosition;
        private System.Windows.Forms.NumericUpDown numChannel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown numRamp;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numTime;
    }
}
