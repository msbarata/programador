Public Class Form1
    Private Sub Label3_Click(sender As Object, e As EventArgs) Handles Label3.Click

    End Sub

    Private Sub btnCalculo_Click(sender As Object, e As EventArgs) Handles btnCalculo.Click
        lblDias.Text = DateDiff(DateInterval.Day, DateTimePicker1.Value, DateTimePicker2.Value)
    End Sub

    Private Sub btnApagar_Click(sender As Object, e As EventArgs) Handles btnApagar.Click
        Dim valorApagar As Integer
        Dim valorApagar2 As Integer

        valorApagar = DateDiff(DateInterval.Day, DateTimePicker1.Value, DateTimePicker2.Value)

        If valorApagar >= 10 Then
            valorApagar2 = valorApagar * 30
        ElseIf valorApagar < 10 Then
            valorApagar2 = valorApagar * 20
        End If

        lblApagar.Text = valorApagar2 & " $"

    End Sub
End Class
