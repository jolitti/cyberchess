add_library(Point point/Point.cpp)
add_library(Board board/Board.cpp)

add_library(Move move/Move.cpp)
add_library(Capture move/capture/Capture.cpp)
add_library(EnPassant move/enpassant/EnPassant.cpp)
add_library(Promotion move/promotion/Promotion.cpp)

add_library(History history/History.cpp)
add_library(Movecalc movecalc/Movecalc.cpp)

add_library(Bot player/bot/Bot.cpp)