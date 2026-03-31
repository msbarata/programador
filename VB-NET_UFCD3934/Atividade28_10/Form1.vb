Public Class Form1
    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged
        Label2.Visible = True
        Label2.ForeColor = Color.Brown

        Select Case ListBox1.SelectedItem
            Case "Mar e Corais"
                Label2.Text = "Corais de Pernambuco:
Piscinas naturais com águas cristalinas e recifes, para mergulho e contemplação!"
                PictureBox2.Image = My.Resources.MareCorais
            Case "Campos Europeus"
                Label2.Text = "Campo de Pinheiros – Europa:
Paisagens serenas com pinheiros, perfeitos para caminhadas e contato com a natureza!"
                PictureBox2.Image = My.Resources.CampoEuropeu
            Case "Grandes Rios"
                Label2.Text = "Rio Tejo:
Majestoso rio que corta Portugal, banhando Lisboa e com belas vistas ao entardecer!"
                PictureBox2.Image = My.Resources.RioEuropeu
            Case "Montanhas Nevadas"
                Label2.Text = "Vale Nevado – Argentina:
Destino andino famoso por suas montanhas nevadas e esportes de inverno de tirar o fôlego!"
                PictureBox2.Image = My.Resources.MontanhaseNeve
            Case "Belas Cachoeiras"
                Label2.Text = "Cachoeira Foz do Iguaçu:
Impressionante conjunto de quedas d’água entre Brasil, Argentina e Paraguai, força e beleza!"
                PictureBox2.Image = My.Resources.Cachoeira

        End Select
    End Sub
End Class
