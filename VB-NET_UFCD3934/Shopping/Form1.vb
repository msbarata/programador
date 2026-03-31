Public Class Form1
    Private Sub Label6_Click(sender As Object, e As EventArgs) Handles Label6.Click

    End Sub

    Private Sub Calcular_Click(sender As Object, e As EventArgs) Handles Calcular.Click
        Const lx As Integer = 100
        Const nb As Integer = 500
        Const sd As Integer = 300
        Const hd As Integer = 80
        Const hm As Integer = 300
        Const am As Integer = 150

        Dim soma As Integer

        If CheckImpressora.Checked = True Then
            soma += lx
        End If
        If CheckNotebook.Checked = True Then
            soma += nb
        End If
        If CheckPC.Checked = True Then
            soma += sd
        End If
        If CheckWebCam.Checked = True Then
            soma += hd
        End If
        If CheckMP4.Checked = True Then
            soma += hm
        End If
        If CheckRouter.Checked = True Then
            soma += am
        End If

        lblTotal.Text = soma.ToString("c")

    End Sub

    Private Sub Limpar_Click(sender As Object, e As EventArgs) Handles Limpar.Click
        CheckImpressora.Checked = False
        CheckNotebook.Checked = False
        CheckPC.Checked = False
        CheckWebCam.Checked = False
        CheckMP4.Checked = False
        CheckRouter.Checked = False

        ' Limpa o texto do rótulo
        lblTotal.Text = ""
    End Sub
End Class
