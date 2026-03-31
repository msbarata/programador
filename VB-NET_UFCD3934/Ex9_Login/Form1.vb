Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub btnLogin_Click(sender As Object, e As EventArgs) Handles btnLogin.Click
        Dim nome As String = txtUtilizador.Text
        Dim password As String = txtPassord.Text

        If nome = "Manoel" And password = "iefp123" Then
            MessageBox.Show("Bem vindo Manoel! Acesso permitido.")
        Else
            MessageBox.Show("Utilizador inválido! Acesso negado.")
        End If
    End Sub
End Class
