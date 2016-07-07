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
// 
// git: 3komma3volt
// </summary>
// ---

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ssx32Control
{
    public partial class customSlider : UserControl
    {

        public int PositionMin
        {
            get { return Convert.ToInt16(numPosition.Minimum); }
            set { numPosition.Minimum = value;
                  trackPosition.Minimum = value;
                Invalidate(); 
            }
        }
        public int PositonMax
        {
            get { return Convert.ToInt16(numPosition.Maximum); }
            set { numPosition.Maximum = value;
            trackPosition.Maximum = value;
                Invalidate(); 
            }
        }
        public int Position
        {
            get { return Convert.ToInt16(numPosition.Value); }
            set
            {
                numPosition.Value = value;
                trackPosition.Value = value;
                Invalidate();
            }
        }
        public int Channel
        {
            get { return Convert.ToInt16(numChannel.Value); }
            set { numChannel.Value = value; Invalidate(); }
        }
        public int Ramp
        {
            get { return Convert.ToInt16(numRamp.Value); }
            set { numRamp.Value = value; Invalidate(); }
        }
        public int Time
        {
            get { return Convert.ToInt16(numTime.Value); }
            set { numTime.Value = value; Invalidate(); }
        }
        public bool TimeEnabled
        {
            get { return numTime.Enabled; }
            set { numTime.Enabled = value; Invalidate(); }
        }
        private Size desiredSize = new Size(61, 333);
        public override Size MinimumSize
        {
            get { return desiredSize; }
            set { }
        }
        public override Size MaximumSize
        {
            get { return desiredSize; }
            set { }
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Pen blackPen = new Pen(Color.DarkGray, 1);
            System.Drawing.Graphics formGraphics = this.CreateGraphics();
            formGraphics.DrawRectangle(blackPen, new Rectangle(0, 0, 60, 332));
            blackPen.Dispose();
            formGraphics.Dispose();
        }

        public customSlider()
        {
          
            InitializeComponent();
        }
         
        private void trackPosition_ValueChanged(object sender, EventArgs e)
        {
            numPosition.Value = trackPosition.Value;
            try
            {
                PositionChanged(this, e);
            }
            catch { }
        }

        private void numPosition_ValueChanged(object sender, EventArgs e)
        {
            trackPosition.Value = Convert.ToInt16(numPosition.Value);
        }

        [Category("Action")]
        [Description("Fires when the Slider is moved.")]
        public event EventHandler PositionChanged;

        private void customSlider_Load(object sender, EventArgs e)
        {

        }


 
    }
}
