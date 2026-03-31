Public Class Form1

    Dim salario As Integer
    Dim desconto As Integer
    Dim taxaiva As Integer
    Dim saude As Integer
    Dim SS As Integer
    Dim salariofinal As Integer

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        salario = (txtHoras.Text * txtDias.Text) * txtPrecoHoras.Text
        txtSB.Text = salario

        'Serve para calcular o valor do IVA
        taxaiva = salario * 0.23
        txtIVA.Text = taxaiva

        'Desconto para a saude
        saude = salario * 0.05
        txtSaude.Text = saude

        'Desconto SS
        SS = salario * 0.11
        txtSS.Text = SS

        'Calcule descontos
        desconto = taxaiva + saude + SS
        txtDescontos.Text = desconto

        'Salario Final
        salariofinal = salario - desconto
        TxtOrdenado.Text = salariofinal




    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        txtNome.Text = ""
        txtDias.Text = ""
        txtDescontos.Text = ""
        txtHoras.Text = ""
        txtIVA.Text = ""
        TxtOrdenado.Text = ""
        txtPrecoHoras.Text = ""
        txtSaude.Text = ""
        txtSB.Text = ""
        txtSS.Text = ""


    End Sub
End Class
