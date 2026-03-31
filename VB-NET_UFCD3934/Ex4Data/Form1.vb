Public Class Form1
    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim Dia As Date

        Dia = DateTimePicker1.Value

        MessageBox.Show("A data escolhida é: " & Dia, "Sr. Manoel")

        Label2.Text = "A data escolhida é: " & Dia

    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        ColorDialog1.ShowDialog()
        Me.BackColor = ColorDialog1.Color
    End Sub
End Class