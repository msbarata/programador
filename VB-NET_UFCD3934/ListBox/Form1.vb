Public Class Form1
    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged
        Dim notas As String
        notas = ListBox1.Text
        Label1.Text = ("A sua Classificação é: " & notas)
    End Sub
End Class
