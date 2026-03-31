Imports System.Windows.Forms.VisualStyles.VisualStyleElement

Public Class Form1
    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles btnQuadrado.Click
        Dim c As Double
        Dim d As Double

        Dim A1 As Double

        c = TextBox1.Text
        d = TextBox2.Text

        A1 = c * d

        TextBox5.Text = A1 & " m²"

        Resultado.Items.Add("A área do Quadrado é: " & A1 & " m²")

    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub

    Private Sub Label5_Click(sender As Object, e As EventArgs) Handles Label5.Click

    End Sub

    Private Sub Label6_Click(sender As Object, e As EventArgs) Handles Label6.Click

    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        Dim f As Double
        Dim g As Double

        Dim A2 As Double

        f = TextBox3.Text
        g = TextBox4.Text

        A2 = f * g

        TextBox6.Text = A2 & " m"

        Resultado.Items.Add("A área do Retângulo é: " & A2 & " metros")
    End Sub

    Private Sub Label7_Click(sender As Object, e As EventArgs) Handles Label7.Click

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim j As Double
        Dim l As Double

        Dim A3 As Double

        j = TextBox7.Text
        l = TextBox8.Text

        A3 = j * l / 2

        TextBox9.Text = A3 & " m"

        Resultado.Items.Add("A área do Triângulo é: " & A3 & " metros")
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click

        TextBox1.Text = "0"
        TextBox2.Text = "0"
        TextBox3.Text = "0"
        TextBox4.Text = "0"
        TextBox5.Text = "0"
        TextBox6.Text = "0"
        TextBox7.Text = "0"
        TextBox8.Text = "0"
        TextBox9.Text = "0"
        Resultado.Items.Clear()

    End Sub
End Class
