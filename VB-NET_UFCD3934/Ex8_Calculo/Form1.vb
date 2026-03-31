Public Class Form1
    Private Sub Label3_Click(sender As Object, e As EventArgs) Handles Label3.Click

    End Sub

    Private Sub btnCalculator_Click(sender As Object, e As EventArgs) Handles btnCalculator.Click
        txtLucro.Text = ((txtVenda.Text - txtCompra.Text) / txtCompra.Text) * 100 & "%"
    End Sub
End Class
