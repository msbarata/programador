Public Class Form1
    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles txtMeses.TextChanged

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim pagamento As Single
        Dim pagInicio As DueDate

        If CheckBox1.Checked Then
            pagInicio = DueDate.BegOfPeriod
        Else
            pagInicio = DueDate.EndOfPeriod
        End If

        pagamento = Pmt(0.01 * txtJuros.Text / 12, txtMeses.Text, -txtValor.Text, 0, pagInicio)

        txtVP.Text = pagamento.ToString("#.00")

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        txtJuros.Text = ""
        txtMeses.Text = ""
        txtValor.Text = ""
        txtVP.Text = ""
        CheckBox1.Checked = False

    End Sub
End Class
