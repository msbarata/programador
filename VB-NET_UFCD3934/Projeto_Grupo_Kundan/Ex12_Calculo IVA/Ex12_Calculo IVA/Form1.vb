Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Const valor_hora As Double = 35.0
        Const comIva As Double = 1.23
        Const iva As Double = 0.23

        Dim horas As Double = CDbl(txtHoras.Text)

        Dim mObra As Double = valor_hora * horas
        Dim mObraIva As Double = mObra * iva
        Dim mObraComIva As Double = mObra * comIva

        Dim partes As Double = CDbl(txtCusto.Text)
        Dim partesIva As Double = partes * iva
        Dim partesComIva As Double = partes * comIva

        Dim custoTotal As Double = mObra + partes
        Dim custoTotalIva As Double = mObraIva + partesIva
        Dim custoTotalComIva As Double = mObraComIva + partesComIva

        ListBox1.Items.Clear()

        ListBox1.Items.Add(DateTime.Now.ToString)

        ListBox1.Items.Add("")

        ListBox1.Items.Add("Nome do Cliente: " & txtCliente.Text)

        ListBox1.Items.Add("")

        ListBox1.Items.Add("Valor da mão de obra sem IVA é: " & mObra.ToString("C"))
        ListBox1.Items.Add("Valor do IVA da mão de obra é: " & mObraIva.ToString("C"))
        ListBox1.Items.Add("Valor da mão de obra com IVA é: " & mObraComIva.ToString("C"))
        ListBox1.Items.Add("")

        ListBox1.Items.Add("O valor das peças sem IVA é: " & partes.ToString("C"))
        ListBox1.Items.Add("O valor do IVA das peças é: " & partesIva.ToString("C"))
        ListBox1.Items.Add("O valor das peças com IVA é: " & partesComIva.ToString("C"))
        ListBox1.Items.Add("")

        ListBox1.Items.Add("O total a pagar sem IVA é: " & custoTotal.ToString("C"))
        ListBox1.Items.Add("O total a pagar do IVA é: " & custoTotalIva.ToString("C"))
        ListBox1.Items.Add("O total a pagar com IVA é: " & custoTotalComIva.ToString("C"))

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        txtCliente.Text = ""
        txtHoras.Text = ""
        txtCusto.Text = ""
        ListBox1.Items.Clear()

        txtCliente.Focus()
    End Sub


End Class
