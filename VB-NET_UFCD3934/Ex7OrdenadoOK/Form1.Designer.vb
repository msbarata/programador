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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Label1 = New System.Windows.Forms.Label()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.txtNome = New System.Windows.Forms.TextBox()
        Me.txtPrecoHoras = New System.Windows.Forms.TextBox()
        Me.txtHoras = New System.Windows.Forms.TextBox()
        Me.txtDias = New System.Windows.Forms.TextBox()
        Me.txtIVA = New System.Windows.Forms.TextBox()
        Me.txtSaude = New System.Windows.Forms.TextBox()
        Me.txtSS = New System.Windows.Forms.TextBox()
        Me.txtSB = New System.Windows.Forms.TextBox()
        Me.txtDescontos = New System.Windows.Forms.TextBox()
        Me.TxtOrdenado = New System.Windows.Forms.TextBox()
        Me.Button2 = New System.Windows.Forms.Button()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(287, 28)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(370, 29)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Sistema de Cálculo de Ordenado"
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(61, 12)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(164, 106)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 1
        Me.PictureBox1.TabStop = False
        '
        'PictureBox2
        '
        Me.PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), System.Drawing.Image)
        Me.PictureBox2.Location = New System.Drawing.Point(748, 12)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(164, 106)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox2.TabIndex = 2
        Me.PictureBox2.TabStop = False
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(40, 199)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(111, 13)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Nome do Funcionário:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(40, 279)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(66, 13)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Preço/Hora:"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(40, 371)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(75, 13)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "Horas por Dia:"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(40, 471)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(61, 13)
        Me.Label5.TabIndex = 6
        Me.Label5.Text = "Nº de Dias:"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.ForeColor = System.Drawing.Color.Maroon
        Me.Label6.Location = New System.Drawing.Point(370, 119)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(181, 24)
        Me.Label6.TabIndex = 7
        Me.Label6.Text = "Dedução do  Salário"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(399, 199)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(143, 13)
        Me.Label7.TabIndex = 8
        Me.Label7.Text = "23% IVA - Ordenado Mensal:"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(399, 305)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(58, 13)
        Me.Label8.TabIndex = 9
        Me.Label8.Text = "Saúde 5%:"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(403, 415)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(47, 13)
        Me.Label9.TabIndex = 10
        Me.Label9.Text = "SS 11%:"
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(688, 199)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(70, 13)
        Me.Label10.TabIndex = 11
        Me.Label10.Text = "Salário Bruto:"
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(688, 305)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(61, 13)
        Me.Label11.TabIndex = 12
        Me.Label11.Text = "Descontos:"
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.Location = New System.Drawing.Point(688, 415)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(81, 13)
        Me.Label12.TabIndex = 13
        Me.Label12.Text = "Salário Líquido:"
        '
        'Button1
        '
        Me.Button1.BackColor = System.Drawing.Color.CadetBlue
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.ForeColor = System.Drawing.SystemColors.ButtonFace
        Me.Button1.Location = New System.Drawing.Point(402, 503)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(211, 56)
        Me.Button1.TabIndex = 14
        Me.Button1.Text = "Calcular"
        Me.Button1.UseVisualStyleBackColor = False
        '
        'txtNome
        '
        Me.txtNome.Location = New System.Drawing.Point(158, 199)
        Me.txtNome.Name = "txtNome"
        Me.txtNome.Size = New System.Drawing.Size(220, 20)
        Me.txtNome.TabIndex = 15
        '
        'txtPrecoHoras
        '
        Me.txtPrecoHoras.Location = New System.Drawing.Point(158, 279)
        Me.txtPrecoHoras.Name = "txtPrecoHoras"
        Me.txtPrecoHoras.Size = New System.Drawing.Size(100, 20)
        Me.txtPrecoHoras.TabIndex = 16
        '
        'txtHoras
        '
        Me.txtHoras.Location = New System.Drawing.Point(170, 371)
        Me.txtHoras.Name = "txtHoras"
        Me.txtHoras.Size = New System.Drawing.Size(100, 20)
        Me.txtHoras.TabIndex = 17
        '
        'txtDias
        '
        Me.txtDias.Location = New System.Drawing.Point(158, 471)
        Me.txtDias.Name = "txtDias"
        Me.txtDias.Size = New System.Drawing.Size(100, 20)
        Me.txtDias.TabIndex = 18
        '
        'txtIVA
        '
        Me.txtIVA.Location = New System.Drawing.Point(548, 196)
        Me.txtIVA.Name = "txtIVA"
        Me.txtIVA.Size = New System.Drawing.Size(100, 20)
        Me.txtIVA.TabIndex = 19
        '
        'txtSaude
        '
        Me.txtSaude.Location = New System.Drawing.Point(464, 305)
        Me.txtSaude.Name = "txtSaude"
        Me.txtSaude.Size = New System.Drawing.Size(100, 20)
        Me.txtSaude.TabIndex = 20
        '
        'txtSS
        '
        Me.txtSS.Location = New System.Drawing.Point(464, 412)
        Me.txtSS.Name = "txtSS"
        Me.txtSS.Size = New System.Drawing.Size(100, 20)
        Me.txtSS.TabIndex = 21
        '
        'txtSB
        '
        Me.txtSB.Location = New System.Drawing.Point(792, 196)
        Me.txtSB.Name = "txtSB"
        Me.txtSB.Size = New System.Drawing.Size(169, 20)
        Me.txtSB.TabIndex = 22
        '
        'txtDescontos
        '
        Me.txtDescontos.Location = New System.Drawing.Point(792, 304)
        Me.txtDescontos.Name = "txtDescontos"
        Me.txtDescontos.Size = New System.Drawing.Size(155, 20)
        Me.txtDescontos.TabIndex = 23
        '
        'TxtOrdenado
        '
        Me.TxtOrdenado.Location = New System.Drawing.Point(801, 415)
        Me.TxtOrdenado.Name = "TxtOrdenado"
        Me.TxtOrdenado.Size = New System.Drawing.Size(146, 20)
        Me.TxtOrdenado.TabIndex = 24
        '
        'Button2
        '
        Me.Button2.BackColor = System.Drawing.Color.CadetBlue
        Me.Button2.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button2.ForeColor = System.Drawing.SystemColors.ButtonFace
        Me.Button2.Location = New System.Drawing.Point(402, 575)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(211, 56)
        Me.Button2.TabIndex = 25
        Me.Button2.Text = "Limpar"
        Me.Button2.UseVisualStyleBackColor = False
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1016, 660)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.TxtOrdenado)
        Me.Controls.Add(Me.txtDescontos)
        Me.Controls.Add(Me.txtSB)
        Me.Controls.Add(Me.txtSS)
        Me.Controls.Add(Me.txtSaude)
        Me.Controls.Add(Me.txtIVA)
        Me.Controls.Add(Me.txtDias)
        Me.Controls.Add(Me.txtHoras)
        Me.Controls.Add(Me.txtPrecoHoras)
        Me.Controls.Add(Me.txtNome)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label12)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents PictureBox2 As PictureBox
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents Label8 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents Label10 As Label
    Friend WithEvents Label11 As Label
    Friend WithEvents Label12 As Label
    Friend WithEvents Button1 As Button
    Friend WithEvents txtNome As TextBox
    Friend WithEvents txtPrecoHoras As TextBox
    Friend WithEvents txtHoras As TextBox
    Friend WithEvents txtDias As TextBox
    Friend WithEvents txtIVA As TextBox
    Friend WithEvents txtSaude As TextBox
    Friend WithEvents txtSS As TextBox
    Friend WithEvents txtSB As TextBox
    Friend WithEvents txtDescontos As TextBox
    Friend WithEvents TxtOrdenado As TextBox
    Friend WithEvents Button2 As Button
End Class
