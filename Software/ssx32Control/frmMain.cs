// --------------------------------------------------------------------------------------------------------------------
//
// Copyright (C) 2016 berndp
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/. 
// </copyright>
// <summary>
// Test software for the SSX32 servo controller
// Keep this header!
// git: 3komma3volt
// </summary>
// ---


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;


namespace ssx32Control
{
    public partial class frmMain : Form
    {
        static SerialPort ssxSerialPort = new SerialPort("COM1", 19200);
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            refreshSerialPorts();
            createSliders();
            for(int i = 1; i<=32; i++)
            cmbBoardNumber.Items.Add(i.ToString());
            cmbBoardNumber.SelectedIndex = 0;

        }

        private void refreshSerialPorts()
        {
            string[] ports = SerialPort.GetPortNames();
            cmbSerialPort.Items.Clear();
            foreach (string port in ports)
            {
                cmbSerialPort.Items.Add(port);
            }
        }

        private void createSliders()
        {
            int sliderNum = 0;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    customSlider servoSlider = new customSlider();
                    servoSlider.Location = new Point(6 + j * 62, 6 + i * 333);
                    servoSlider.Channel = 1+ sliderNum++;
                    servoSlider.PositionChanged += new EventHandler(servoSlider_PositionChanged);
                    panelSliders.Controls.Add(servoSlider);
                }
            }
        }
        void servoSlider_PositionChanged(object sender, EventArgs e)
        {
            customSlider sld = (customSlider)sender;   
            setServo(sld.Channel, sld.Position, sld.Ramp, sld.Time);
        }

        private void setServo(int channel, int position, int speed, int time)
        {
          // debug:  MessageBox.Show("@SSX32 $"+cmbBoardNumber.SelectedItem.ToString()+" #"+channel.ToString()+" S"+speed.ToString()+" P"+position.ToString()+"\r");
            ssxSerialPort.Write("@SSX32 $"+cmbBoardNumber.SelectedItem.ToString()+" #"+channel.ToString()+" S"+speed.ToString()+" P"+position.ToString()+"\r");
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            refreshSerialPorts();
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (btnConnect.Text == "Connect")
                {
                    ssxSerialPort.PortName = cmbSerialPort.SelectedItem.ToString();
                    ssxSerialPort.Open();
                    btnConnect.Text = "Disconnect";
                }
                else
                {
                    ssxSerialPort.Close();
                    btnConnect.Text = "Connect";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error while connecting to serial port", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Copyright (C) 2016 berndp " + Environment.NewLine +
"" + Environment.NewLine +
"This program is free software: you can redistribute it and/or modify" + Environment.NewLine +
"it under the terms of the GNU General Public License as published by" + Environment.NewLine +
"the Free Software Foundation, either version 3 of the License, or" + Environment.NewLine +
"(at your option) any later version." + Environment.NewLine +
"" + Environment.NewLine +
"This program is distributed in the hope that it will be useful," + Environment.NewLine +
"but WITHOUT ANY WARRANTY; without even the implied warranty of" + Environment.NewLine +
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" + Environment.NewLine +
"GNU General Public License for more details." + Environment.NewLine +
"" + Environment.NewLine +
"You should have received a copy of the GNU General Public License" + Environment.NewLine +
"along with this program.  If not, see http://www.gnu.org/licenses/. " + Environment.NewLine +
"Test software for the SSX32 servo controller" + Environment.NewLine +
"" + Environment.NewLine +
"git: 3komma3volt" + Environment.NewLine);
        }

        private void btnOn_Click(object sender, EventArgs e)
        {
            ssxSerialPort.Write("@SSX32 $"+cmbBoardNumber.SelectedItem.ToString()+" !ON\r");
        }

        private void btnOff_Click(object sender, EventArgs e)
        {
            ssxSerialPort.Write("@SSX32 $" + cmbBoardNumber.SelectedItem.ToString() + " !OFF\r");
        }

    }
}
