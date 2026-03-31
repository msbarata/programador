Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Declaração de Variáveis do tipo String

        Dim nome As String

        nome = InputBox("Digite o seu Nome...")

        MsgBox("Benvindo " + nome)

    End Sub

    Private Sub PictureBox1_Click(sender As Object, e As EventArgs) Handles PictureBox1.Click

    End Sub
End Class
