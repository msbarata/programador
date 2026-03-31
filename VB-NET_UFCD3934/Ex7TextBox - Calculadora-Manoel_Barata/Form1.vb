Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim valor1 As Integer
        Dim valor2 As Integer
        Dim soma As Integer

        valor1 = TextBox1.Text
        valor2 = TextBox2.Text
        soma = valor1 + valor2

        Label4.Text = soma

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        TextBox1.Text = ""
        TextBox2.Text = ""
        Label4.Text = ""
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles TextBox2.TextChanged

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Dim valor1 As Integer
        Dim valor2 As Integer
        Dim subtrair As Integer

        valor1 = TextBox1.Text
        valor2 = TextBox2.Text
        subtrair = valor2 - valor1

        Label4.Text = subtrair
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Dim valor1 As Integer
        Dim valor2 As Integer
        Dim multiplica As Integer

        valor1 = TextBox1.Text
        valor2 = TextBox2.Text
        multiplica = valor1 * valor2

        Label4.Text = multiplica
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Dim valor1 As Double
        Dim valor2 As Double
        Dim dividir As Double

        valor1 = TextBox1.Text
        valor2 = TextBox2.Text
        dividir = valor2 / valor1

        Label4.Text = dividir.ToString()
    End Sub
End Class
