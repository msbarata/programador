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
        Me.Label4 = New System.Windows.Forms.Label()
        Me.btnCalculator = New System.Windows.Forms.Button()
        Me.txtCompra = New System.Windows.Forms.TextBox()
        Me.txtVenda = New System.Windows.Forms.TextBox()
        Me.txtLucro = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BackColor = System.Drawing.Color.DimGray
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.Color.Transparent
        Me.Label1.Location = New System.Drawing.Point(230, 18)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(327, 25)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Aplicação - Cálculo de Lucros"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(49, 48)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(123, 20)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Valor_Compra"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(49, 137)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(113, 20)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Valor_Venda"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(49, 218)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(128, 20)
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "Margem_Lucro"
        '
        'btnCalculator
        '
        Me.btnCalculator.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnCalculator.Location = New System.Drawing.Point(480, 229)
        Me.btnCalculator.Name = "btnCalculator"
        Me.btnCalculator.Size = New System.Drawing.Size(183, 45)
        Me.btnCalculator.TabIndex = 4
        Me.btnCalculator.Text = "Calcular"
        Me.btnCalculator.UseVisualStyleBackColor = True
        '
        'txtCompra
        '
        Me.txtCompra.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtCompra.Location = New System.Drawing.Point(53, 83)
        Me.txtCompra.Name = "txtCompra"
        Me.txtCompra.Size = New System.Drawing.Size(289, 24)
        Me.txtCompra.TabIndex = 5
        '
        'txtVenda
        '
        Me.txtVenda.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtVenda.Location = New System.Drawing.Point(53, 170)
        Me.txtVenda.Name = "txtVenda"
        Me.txtVenda.Size = New System.Drawing.Size(289, 24)
        Me.txtVenda.TabIndex = 6
        '
        'txtLucro
        '
        Me.txtLucro.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtLucro.Location = New System.Drawing.Point(53, 250)
        Me.txtLucro.Name = "txtLucro"
        Me.txtLucro.Size = New System.Drawing.Size(289, 24)
        Me.txtLucro.TabIndex = 7
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.txtLucro)
        Me.Controls.Add(Me.txtVenda)
        Me.Controls.Add(Me.txtCompra)
        Me.Controls.Add(Me.btnCalculator)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Cálculo_Lucros"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents btnCalculator As Button
    Friend WithEvents txtCompra As TextBox
    Friend WithEvents txtVenda As TextBox
    Friend WithEvents txtLucro As TextBox
End Class
