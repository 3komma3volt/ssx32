namespace ssx32Control
{
    partial class frmMain
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

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.panelSliders = new System.Windows.Forms.Panel();
            this.toolBarTop = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.cmbSerialPort = new System.Windows.Forms.ToolStripComboBox();
            this.btnConnect = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.btnOn = new System.Windows.Forms.ToolStripButton();
            this.btnOff = new System.Windows.Forms.ToolStripButton();
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.cmbBoardNumber = new System.Windows.Forms.ToolStripComboBox();
            this.toolBarTop.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelSliders
            // 
            this.panelSliders.Location = new System.Drawing.Point(12, 28);
            this.panelSliders.Name = "panelSliders";
            this.panelSliders.Size = new System.Drawing.Size(1004, 682);
            this.panelSliders.TabIndex = 0;
            // 
            // toolBarTop
            // 
            this.toolBarTop.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.cmbSerialPort,
            this.btnConnect,
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripSeparator1,
            this.toolStripLabel2,
            this.cmbBoardNumber,
            this.btnOn,
            this.btnOff});
            this.toolBarTop.Location = new System.Drawing.Point(0, 0);
            this.toolBarTop.Name = "toolBarTop";
            this.toolBarTop.Size = new System.Drawing.Size(1030, 25);
            this.toolBarTop.TabIndex = 1;
            this.toolBarTop.Text = "toolStrip1";
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(63, 22);
            this.toolStripLabel1.Text = "Serial port:";
            // 
            // cmbSerialPort
            // 
            this.cmbSerialPort.Name = "cmbSerialPort";
            this.cmbSerialPort.Size = new System.Drawing.Size(121, 25);
            // 
            // btnConnect
            // 
            this.btnConnect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnConnect.Image = ((System.Drawing.Image)(resources.GetObject("btnConnect.Image")));
            this.btnConnect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(56, 22);
            this.btnConnect.Text = "Connect";
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(50, 22);
            this.toolStripButton1.Text = "Refresh";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton2.Text = "?";
            this.toolStripButton2.Click += new System.EventHandler(this.toolStripButton2_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // btnOn
            // 
            this.btnOn.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnOn.Image = ((System.Drawing.Image)(resources.GetObject("btnOn.Image")));
            this.btnOn.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnOn.Name = "btnOn";
            this.btnOn.Size = new System.Drawing.Size(27, 22);
            this.btnOn.Text = "On";
            this.btnOn.Click += new System.EventHandler(this.btnOn_Click);
            // 
            // btnOff
            // 
            this.btnOff.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnOff.Image = ((System.Drawing.Image)(resources.GetObject("btnOff.Image")));
            this.btnOff.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnOff.Name = "btnOff";
            this.btnOff.Size = new System.Drawing.Size(28, 22);
            this.btnOff.Text = "Off";
            this.btnOff.Click += new System.EventHandler(this.btnOff_Click);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(51, 22);
            this.toolStripLabel2.Text = "Board #:";
            // 
            // cmbBoardNumber
            // 
            this.cmbBoardNumber.Name = "cmbBoardNumber";
            this.cmbBoardNumber.Size = new System.Drawing.Size(75, 25);
            this.cmbBoardNumber.Text = "1";
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1030, 716);
            this.Controls.Add(this.toolBarTop);
            this.Controls.Add(this.panelSliders);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.ShowIcon = false;
            this.Text = "SSX32Control - berndp";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.toolBarTop.ResumeLayout(false);
            this.toolBarTop.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panelSliders;
        private System.Windows.Forms.ToolStrip toolBarTop;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripComboBox cmbSerialPort;
        private System.Windows.Forms.ToolStripButton btnConnect;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripLabel toolStripLabel2;
        private System.Windows.Forms.ToolStripComboBox cmbBoardNumber;
        private System.Windows.Forms.ToolStripButton btnOn;
        private System.Windows.Forms.ToolStripButton btnOff;
    }
}

