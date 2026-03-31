Public Class Form1
    Private Sub RadioButton1_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton1.CheckedChanged
        'Aqui a cor do fundo muda

        Me.BackColor = Color.Red
    End Sub

    Private Sub RadioButton2_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton2.CheckedChanged

        Me.BackColor = Color.Blue
    End Sub

    Private Sub RadioButton3_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton3.CheckedChanged
        'Aqui a cor do texto muda

        Me.ForeColor = Color.White
    End Sub

    Private Sub RadioButton4_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton4.CheckedChanged

        Me.ForeColor = Color.Yellow
    End Sub

    Private Sub RadioButton5_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton5.CheckedChanged
        Me.ForeColor = Color.Green
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        'Alterar a propriedade Enabled = True

        lblDigital.Text = TimeOfDay
    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub

    Private Sub Label3_Click(sender As Object, e As EventArgs) Handles Label3.Click

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If TextBox1.Text > 0 And TextBox1.Text <= 100 Then
            MessageBox.Show("Inseriu um valor correcto" & vbCrLf & "Teste")
        Else
            MessageBox.Show("Precisa inserir valores de 1 a 100")
        End If
    End Sub
End Class
