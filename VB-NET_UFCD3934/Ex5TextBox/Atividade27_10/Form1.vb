Public Class Form1
    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged
        Label2.Visible = True
        Label2.ForeColor = Color.Brown

        Select Case ListBox1.SelectedItem
            Case "Português"
                Label2.Text = "Ola !! Bemvindos a Portugal!"
                PictureBox2.Image = My.Resources.Portugal
            Case "Inglês"
                Label2.Text = "Hi !! Welcome to England!"
                PictureBox2.Image = My.Resources.Inglaterra
            Case "Espanhol"
                Label2.Text = "Hola !! Bienvendo a España!"
                PictureBox2.Image = My.Resources.Espanha
            Case "Italiano"
                Label2.Text = "Ciao!! Benevenuto in Italia!"
                PictureBox2.Image = My.Resources.Italia
            Case "Alemão"
                Label2.Text = "Hallo!! Willkommen in Portugal!"
            Case "Francês"
                Label2.Text = "Salut !! Bievenue en Francês!"
                PictureBox2.Image = My.Resources.França
            Case "Japão"
                Label2.Text = "Kon'nichiwa! Porutogaru e yōkoso!"
        End Select
    End Sub
End Class
