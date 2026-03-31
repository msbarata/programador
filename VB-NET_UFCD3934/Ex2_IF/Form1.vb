Public Class Form1
    Private Sub RadioButton1_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton1.CheckedChanged


        If RadioButton1.Checked = True Then
            MessageBox.Show("Você escolheu a linguagem C++")

        ElseIf RadioButton2.Checked = True Then

            MessageBox.Show("Você escolheu a linguagem VB.NET")
        End If
    End Sub
End Class
