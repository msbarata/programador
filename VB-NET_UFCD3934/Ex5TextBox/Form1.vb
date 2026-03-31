Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim valor1 As Integer
        Dim valor2 As Integer
        Dim soma As Integer

        valor1 = TextBox1.Text
        valor2 = TextBox2.Text
        soma = valor1 * valor2

        Label4.Text = soma

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        TextBox1.Text = ""
        TextBox2.Text = ""
        Label4.Text = ""
    End Sub
End Class
