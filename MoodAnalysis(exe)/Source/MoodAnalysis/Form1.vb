Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub judge_Click(sender As Object, e As EventArgs) Handles judge.Click
        Dim moodpoint, p(5), x(5) As Double
        Dim txtbox() As Windows.Forms.TextBox   'コントロールをまとめる
        Dim txtlabel() As Windows.Forms.Label   '同上
        Dim i, count As Integer
        Dim GathAtt As Integer = NumericUpDown2.Value
        Dim t, S As Double
        Dim getmes As Boolean = True 'エラー時はムード値を求めない
        txtbox = New TextBox() {Me.EvalNum1, Me.EvalNum2, Me.EvalNum3, Me.EvalNum4, Me.EvalNum5, Me.EvalNum6, Me.EvalNum7, Me.EvalNum8, Me.EvalNum9, Me.EvalNum10}
        txtlabel = New Label() {Me.Number1, Me.Number2, Me.Number3, Me.Number4, Me.Number5, Me.Number6, Me.Number7, Me.Number8, Me.Number9, Me.Number10}
        x(0) = 0
        While txtbox(i).Visible '表示分を抽出
            count += 1
            i += 1
            If i = 10 Then
                Exit While
            End If
        End While
        For i = 0 To count - 1
            If Not txtbox(i).Text.Equals("") Then
                x(0) += 1 / 5 * (Integer.Parse(txtbox(i).Text))
            Else
                MessageBox.Show("Please input a numerical value in Score textbox.")
                getmes = False
                Exit For
            End If
        Next i
        x(0) /= count
        p(0) = x(0) '美しさ指数
        If Not (GathAtt = 0) Then
            p(1) = GathAtt * -10000
        Else
            p(1) = 20
        End If  '第三者指数
        If Not TextBox1.Text.Equals("") Then
            x(2) = Double.Parse(TextBox1.Text)
        Else
            MessageBox.Show("Please input a numerical value in Illuminance textbox.")
            getmes = False
        End If
        p(2) = (1 / 5) * (104 - 2 * ((x(2) / 20) + (20 / x(2))))    '照度指数
        If Not TextBox2.Text.Equals("") Then
            x(3) = TextBox2.Text
        Else
            MessageBox.Show("Please input a numerical value in Noise textbox.")
            getmes = False
        End If
        If (x(3) < 20 And x(3) >= 0) Then
            p(3) = 20
        ElseIf (x(3) < 70 And x(3) >= 20) Then
            t = 100 - 2 * (x(3) - 20)
            p(3) = 30 - (1000 / t)
        Else
            p(3) = -1 / 0
        End If '静けさ指数
        If Not TextBox2.Text.Equals("") Then
            x(4) = TextBox3.Text
        Else
            MessageBox.Show("Please input a numerical value in Times textbox.")
            getmes = False
        End If
        If (x(4) < 30 And x(4) > 0) Then
            S = (100 / 30) * x(4)
        ElseIf (x(4) <= 60 And x(4) >= 30) Then
            S = 100
        Else
            S = 100 - 5 * (x(4) - 60)
        End If
        p(4) = (1 / 5) * S  '見つめ合い指数
        For i = 0 To 4
            moodpoint += p(i)
        Next i
        If getmes Then
            p1md.Text = Math.Round(p(0), 2, MidpointRounding.AwayFromZero)
            p2md.Text = Math.Round(p(1), 2, MidpointRounding.AwayFromZero)
            p3md.Text = Math.Round(p(2), 2, MidpointRounding.AwayFromZero)
            p4md.Text = Math.Round(p(3), 2, MidpointRounding.AwayFromZero)
            p5md.Text = Math.Round(p(4), 2, MidpointRounding.AwayFromZero)
            mpmd.Text = Math.Round(moodpoint, 2, MidpointRounding.AwayFromZero)
        End If
    End Sub

    Private Sub NumericUpDown1_ValueChanged(sender As Object, e As EventArgs) Handles NumericUpDown1.ValueChanged
        Dim txtbox() As Windows.Forms.TextBox
        Dim txtlabel() As Windows.Forms.Label
        Dim tf As Boolean
        Dim i As Integer
        Dim cell As Integer = NumericUpDown1.Value
        NumericUpDown1.Minimum = 1
        NumericUpDown1.Maximum = 10
        txtbox = New TextBox() {Me.EvalNum1, Me.EvalNum2, Me.EvalNum3, Me.EvalNum4, Me.EvalNum5, Me.EvalNum6, Me.EvalNum7, Me.EvalNum8, Me.EvalNum9, Me.EvalNum10}
        txtlabel = New Label() {Me.Number1, Me.Number2, Me.Number3, Me.Number4, Me.Number5, Me.Number6, Me.Number7, Me.Number8, Me.Number9, Me.Number10}
        tf = txtbox(cell - 1).Visible
        If tf Then
            For i = cell To 9   '現数値から上は非表示
                txtbox(i).Visible = False
                txtlabel(i).Visible = False
            Next i
        Else
            txtbox(cell - 1).Visible = True '現数値は表示
            txtlabel(cell - 1).Visible = True
        End If
    End Sub

    Private Sub NumericUpDown2_ValueChanged(sender As Object, e As EventArgs) Handles NumericUpDown2.ValueChanged
        NumericUpDown2.Minimum = 0
    End Sub
End Class