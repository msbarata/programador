Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles btnSoma.Click
        Dim a As Integer
        Dim b As Integer
        Dim total As Integer
        a = InputBox("Insira um valor")
        b = InputBox("Insira outro valor")
        total = a + b

        MsgBox("O valor total é " & total)
        Label2.Text = total
    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub
End Class
