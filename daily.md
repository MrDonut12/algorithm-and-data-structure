###### 29/06/2026
CSES - Problem: Grid Path Description
// Tư duy Pruning còn yếu nghề, cần rèn thêm
// Loạn cái vụ từ dfs -> backtrack, lỏ cái visited mà loay hoay cả ngày k bt tại sao sai =)))))))
// Cân nhắc kỹ thứ tự thực thi khi backtrackking
// Bài này là backtracking nhưng về cơ bản thử hết thì tốn tận 4^49, TLE là cái chắc, càng nhiều '?' khả năng TLE càng cao, vì thế ta hướng tiếp cận của bài này là pruning
// Trong bài trình bày kỹ 3 ý tưởng prunning, đọc code không giải thích thêm.

###### 30/06/2026
CSES - Problem: Apartments
// Tư duy sorting, ban đầu là nghĩ là chặt nhị phân nhưng khi xét đến việc tìm được và đánh dấu thì cách này đang làm sai ý nghĩa của chặt nhị phân, vì thế vẫn sẽ là sorting nhưng áp dụng tư duy hai con trỏ, trong đó xét nếu mảng apartment, căn hộ hiện tại nằm trong nhu cầu của người mua thì pass ng mua và căn hộ đó, tức l++, r++, nếu căn hộ thấp hơn nhu cầu của người mua, pass căn hộ, r++, vì đã sort rồi nên nếu người mua hiện tại kh đạt thì người sau cũng sẽ không đạt (sắp xếp tăng dần), nếu căn hộ cao hơn nhu cầu người mua, pass người mua =))))
// Btw giải bài này khá mượt
###### 01/07/2026
CSES - Problem: Concert Tickets
// Bài này gần như có thể sorting rồi dùng binary search để giải quyết vấn đề, tuy nhiên tính chất là phải đánh dấu rằng cái vé này đã được bán đi rồi và ta càng không thể dùng hai con trỏ vì số lượng khách xếp hàng là kh được thay đổi, nên dù sort hay không thì yếu tố này đang làm mất ý nghĩa của binary search và khó ứng dụng, đặc biệt là trong mảng tĩnh, tuy thế nếu không dùng binary search mà dùng linear search hay một cơ chế mapping thì mình thấy đang không khả thi và có lẽ bị vài lỗi vặt (chưa kiểm chứng nhưng linear search thì TLE là cái chắc)
// Vì thế bài này mình đã sử dụng multiset, một dạng lưu các phần tử trùng theo thứ tứ sắp xếp asc/desc tùy thích và cho phép trùng, mỗi lần xóa một phần tử là ~O(1), không biết edge case nó có bị TLE không nhưng ý tưởng cơ bản là binary search (theo upper_bound), nếu có thì đá nó ra khỏi multiset, thế thôi, loại bỏ trực tiếp yếu tố đánh dấu, và vì đây là mảng động nên khi xóa thì nó vẫn là một mảng tăng dần và vẫn có thể search lại một lần nx, nếu khong có thì in ra -1
// Yep, cách này đã giúp mình AC bài này

CSES - Problem: Restaurant Customer
// Bài này mình vướng một lỗi khá tiêu điển là đọc không kỹ đề bài, ở đây bài cho thời gian khách vào và kết thúc, họ hỏi tại mỗi thời điểm thì khách đông nhất, mình lại gáng đi tính sau khi thời điểm kết thúc thì số lượng khách hàng nối nhau nhiều nhất là bao nhiêu =))), là core idea của bài Movie Festival (Kết thúc thì xem được tối đa bao nhiêu bộ phim)
// Bài này áp dụng idea sweep line đơn giản khá ấn tượng, bằng việc sử dụng map (Red-Black Tree) để lưu số khách hàng vào và ra từng mốc, áp đặt +1 cho khách hàng vào tại thời điểm này, -1 cho số khách hàng rời ở thời điểm kia, ta sàng một lần lại bằng cách tính tổng cộng dồn ở các thời điểm, dùng một biến đơn là đủ, ta sẽ tìm ra được max khách hàng tại một thời điểm chỉ qua 1 lần duyệt


###### 04/07/2026
CSES - Problem: Sum of Two values
// Vấn đề này đã được giải bằng Sorting và Two Pointer trước đó, thể hiện đúng tinh thần sort and searching của bài, nên lúc này mình đã giải lại bằng kỹ thuật lưu index thông qua hash map. Ý tưởng ban đầu là mình sử dụng cặp {key, value} là dạng <ll, pair <ll, ll>>>. Sử dụng pair là để lưu hai vị trí khác nhau, tong quá trình xử lí sẽ xét thêm được trường hợp trùng index mà tính ra tổng, cái này luôn đúng vì cặp vị trí có cùng key luôn luon khác nhau, và đã AC 80% bài, còn lại bị TLE
// mình đã xem kĩ các test, do là độ dài test paste vào k đủ nên toi sẽ mô tả như sau, Mình đã giả định là người ra đề cố tình để n là tối đa, tức 2.10^5, và x rất nhỏ, các ai nó rất lớn khiến cho việc tìm cặp số có tổng = x là không bao giờ xảy ra, khiến việc chạy hết đống này làm nó bị TLE, các test khác n có thể rất lớn nhưng do luôn tồn tại một cặp nên mình có thể kết thúc sớm vòng lặp mà không chạy hết như trường hợp TLE ở bài, tất nhiên với n = 2.10^5, và độ phức tạp khi dùng hash map là O(n), đều này chỉ ra rằng vấn đề nằm ở cách vận hành cấu trúc hash_map, và test của đề này là anti-hash
// nguyên nhân nằm ở việc người ra đề cố tình ra các test sao cho khi chạy, các hashcode đều cố tính rời vào một bucket, nên khi find, nó phải vào bucket và duyệt hết cái đống hashcode đó, khiến worstcase của thuật toán này rơi vào O(n^2) thay vì O(n) như dự tính, nên ở đây ta chỉ cần thay hash map thành map thông thường, dạng map sử dụng Cây đỏ đen là AC, chấp nhận mỗi lần find hay insert đều tốn log(n), nhưng nó ổn định và không dính worst case như việc sử dụng hash map, thuật toán ta xây dựng lúc này là O(nlogn), không TLE như giải thuật chính
// Bài học chỉ ra: Luôn cân nhắc thật kĩ trade-off, worst case của các thao tác trước khi sử dụng một cấu trúc dữ liệu cụ thể

CSES - Maximum Subarray Sum
// Idea khá tiêu điển, không bàn thêm. Core là để lấy tổng lớn nhất của một đoạn có chứa số âm, giả định ta có prefixSum đoạn 1...n, lấy max_sum(prefixSum1 - min_sum(frefixsum2), index max phải hơn min, nếu ta xét giá trị minval là prefixsum từ 1...n-1, xét mỗi prefixsum hiện tại - minval sau đó cập nhật, nếu thấy prefixsum nhỏ hơn minval, cập nhật nó

CSES - Missing Coin Sum
// Bài này tìm ra tổng nhỏ nhất có thể tạo được từ các phần tử con, không phải đoạn, nên ở đây phải sort trước để tính tổng từ từ lên vì các phần tử đầu luôn là phần tử nhỏ nhất, ta dễ dàng tìm được phần tử không thể tạo được ở giai đoạn này
// Quan sát thấy, nếu cộng dần các phần tử này lên ta có thể tạo ra được một khoảng liên tục thông qua quy tắc cực kì đơn giản sao (cho mảng gồm 1 2 2 8)
đầu tiên là 1, ta chứng minh phần tử này tạo được tổng 1, tới 2, ta thu được một khoảng là [0, 1] và [2 + 0, 2  + 1] -> [0, 1, 2, 3]
// lặp lại tiếp tới số 2, ta chỉ đơn giản là có khoảng [0, 1, 2, 3] và [0 + 2, 1 + 2, 2 + 2, 3 + 2] ta dễ dàng thu được [0, 1, 2, 3, 4, 5] nhưng đến 8, ta để ý kĩ nếu lấy 8 cộng vào khoảng cũ, sẽ ra [8, 9, 10, 11, 12, 13], lọt mất số 7 và đây là đáp án
// Bản chất chỉ cần xét "mốc cũ]" và "[arr(i) + 1/0" xem ở giữa khoảng này có một khoảng trống nào không, ở ngữ cảnh trên là đang thiếu mất số 7, đây chính xác là kết quả của bài toán ta cần tìm
// Hồi trước mình có gairi dc bài này nhưng chưa hiểu hoàn toàn bản chất, chăm chú tìm cách chứng minh ở một dãy số liên tục nào đó, phải thõa đk nào đó thì sẽ luôn có cách tạo ra một dãy liên tục, tuy nhiên khi đổi hướng tiếp cận là tạo ra khoảng mới, lấy số mới cộng khoảng cũ và xét hai khoảng hay ở giữa hai khoảng có trống không thì làm sáng tỏ được core idea của bài, ngoài ra cũng chứng minh được điều kiện để tạo là arr(i) - curr  - 1 > 0

###### 05/07/2026
CSES Problem: Collecting Numbers
// Bài này mình vẫn còn hơi rối chỗ xóa tuần tự, nhưng về cơ bản core idea là ta đi xét tuần tự các số, bằng cách lưu chỉ số hiện tại của số này, sau đó xóa tuần tự từ 1 tới n, khi xóa đồng thứ i, ta sẽ phải xét xem đồng i này có đang đứng trước đồng i - 1 không, nếu có thì bắt buộc phải thêm 1 round vì không xóa cùng round với đồng i - 1, ngược lại thì round không đổi vì có thể xóa cùng đợt với i - 1

CSES Problem: Collecting Numbers II
// Giữ core idea của bài trước, ở đây ta chỉ quan tâm chỉ số thay đổi sau đó ảnh hưởng như thế nào thoi, cụ thể là các chỉ số x, x + 1 và y, y+1, sử dụng set để loại bỏ trùng vì trước đó lỡ dùng vector và nó bị sai, tại dùng vòng lặp for để xét điều kiện cho nhanh
// Bài này setup đơn giản nhưng để tiếp cận và suy ra core idea thì cả một quá trình

###### 06/07/2026
CSES Problem: Playlists
// Bài này sử dụng tư duy sliding window thông qua hai chỉ số i và j, mình sẽ vừa expand chỉ số i cho tới khi gặp trị số trùng thông qua mảng đánh dấu flag, nếu trùng thì sẽ thu ngược chỉ số j lại cho đến khi hết trùng thì thoi
// Bài này mình đã phạm lỗi về cách thu hẹp j, nếu gặp trùng thì mình chỉ đơn giản là j + 1 trong khi rủi ro là việc a[i] đã xuất hiện trước đó nó có thể nằm ở giữa cửa sổ, điều này đã phải khiến mình thay đổi tùy chỉnh thành vòng lặp while
// btw sau đó tiếp tục vướng cách đánh dấu nhưng đã fix được, và code này AC, khổ nỗi mình vướng lại lỗi cũ là trong CSES có test anti-hash, nên mình dùng unordered_map đã khiến cho code này bị TLE, chuyển sang map thì AC

###### 07/07/2026
CSES Problem: Tower
// Bài này idea gần như giống Collecting Idea nhưng bịp ở chỗ là các số có khả năng trùng và độ lớn là 1e9, vì thế cách cũ không khả thi, mình đã có sử dụng vector, sort và implement lại theo cách tương tự, nhưng không giải quyết triệt để được số trùng, có nghĩ theo hướng stack nhưng vẫn chưa tối ưu, bài này mình đã đọc hint, ở đây ta dùng multiset, bằng việc ưu tiên đây số hiện tại vào một số lớn hơn gần nhất, sau đó set lại, ý nghĩa là tạo đk cho các số nhỏ hơn có đk được lắp vào các tower có sẵn, tối ưu hơn dùng stack, nếu không tìm được số nào như vậy thì insert như một tower mới
// Ví dụ 3 8 2 1 5, ta có số 3, sau đó duyệt tới số 8 thì không có số nào lớn hơn 8 cả nên insert, tới số 2, lúc này ta tư duy rằng ta có thể add số 2 vào số 8 nhưng nếu làm vậy thì số 5 sẽ không có cơ hôi được add trong khi tower duy nhất có thể add được là 8, nên ta phải đẩy số 2 lại qua số 3 thông qua upper bound, sau đó set lại, tương tự như vậy tới số 5 nó sẽ add được vào số 8, state cuối cùng là 1 và 5, và đây cũng là 2 tower duy nhất song với đó là đáp án

CSES Problem: Traffic Lights
// Bài này hướng tiếp cận khá mới, nhưng về bản chất ta cần một dữ liệu động để lưu các node luôn tăng dần, ta dùng multiset. Idea ở đây đơn giản là khi một cái đèn mới được add vào, nó luôn chia ở giữa hai node thành hai đoạn mới, nên ta chỉ cần xóa distance cũ và thêm 2 distance mới là xong, multiset luôn đảm bảo dãy tăng dần, mỗi lần xử lí ta in [*(--distance.end())] là ok


// Bài học rút ra từ cả hai bài: Trong một số bài khi cần insert, erase song song và đòi hỏi duy trì rằng dữ liệu phải tăng hay giảm dần, ta có thể cân nhắc giúp multiset
