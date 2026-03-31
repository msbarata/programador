<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.DateTimePicker1 = New System.Windows.Forms.DateTimePicker()
        Me.DateTimePicker2 = New System.Windows.Forms.DateTimePicker()
        Me.btnCalculo = New System.Windows.Forms.Button()
        Me.lblDias = New System.Windows.Forms.Label()
        Me.btnApagar = New System.Windows.Forms.Button()
        Me.lblApagar = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(281, 46)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(152, 20)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Cálculo por Datas"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(68, 117)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(147, 20)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Data de Entrada:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(68, 163)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(129, 20)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Data de Saída:"
        '
        'DateTimePicker1
        '
        Me.DateTimePicker1.Location = New System.Drawing.Point(230, 117)
        Me.DateTimePicker1.Name = "DateTimePicker1"
        Me.DateTimePicker1.Size = New System.Drawing.Size(216, 20)
        Me.DateTimePicker1.TabIndex = 3
        Me.DateTimePicker1.Value = New Date(2025, 10, 21, 14, 26, 5, 0)
        '
        'DateTimePicker2
        '
        Me.DateTimePicker2.Location = New System.Drawing.Point(230, 163)
        Me.DateTimePicker2.Name = "DateTimePicker2"
        Me.DateTimePicker2.Size = New System.Drawing.Size(216, 20)
        Me.DateTimePicker2.TabIndex = 4
        '
        'btnCalculo
        '
        Me.btnCalculo.BackColor = System.Drawing.Color.RosyBrown
        Me.btnCalculo.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnCalculo.Location = New System.Drawing.Point(72, 217)
        Me.btnCalculo.Name = "btnCalculo"
        Me.btnCalculo.Size = New System.Drawing.Size(190, 33)
        Me.btnCalculo.TabIndex = 5
        Me.btnCalculo.Text = "Calcular nº de dias"
        Me.btnCalculo.UseVisualStyleBackColor = False
        '
        'lblDias
        '
        Me.lblDias.AutoSize = True
        Me.lblDias.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblDias.Location = New System.Drawing.Point(299, 223)
        Me.lblDias.Name = "lblDias"
        Me.lblDias.Size = New System.Drawing.Size(24, 20)
        Me.lblDias.TabIndex = 6
        Me.lblDias.Text = "..."
        '
        'btnApagar
        '
        Me.btnApagar.BackColor = System.Drawing.Color.IndianRed
        Me.btnApagar.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnApagar.Location = New System.Drawing.Point(72, 277)
        Me.btnApagar.Name = "btnApagar"
        Me.btnApagar.Size = New System.Drawing.Size(210, 27)
        Me.btnApagar.TabIndex = 7
        Me.btnApagar.Text = "Cálculo Valor a Pagar:"
        Me.btnApagar.UseVisualStyleBackColor = False
        '
        'lblApagar
        '
        Me.lblApagar.AutoSize = True
        Me.lblApagar.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblApagar.Location = New System.Drawing.Point(303, 286)
        Me.lblApagar.Name = "lblApagar"
        Me.lblApagar.Size = New System.Drawing.Size(23, 18)
        Me.lblApagar.TabIndex = 8
        Me.lblApagar.Text = "..."
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.lblApagar)
        Me.Controls.Add(Me.btnApagar)
        Me.Controls.Add(Me.lblDias)
        Me.Controls.Add(Me.btnCalculo)
        Me.Controls.Add(Me.DateTimePicker2)
        Me.Controls.Add(Me.DateTimePicker1)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents DateTimePicker1 As DateTimePicker
    Friend WithEvents DateTimePicker2 As DateTimePicker
    Friend WithEvents btnCalculo As Button
    Friend WithEvents lblDias As Label
    Friend WithEvents btnApagar As Button
    Friend WithEvents lblApagar As Label
End Class
