main = do
  params <- getLine
  let params = [read x::Int | x <- params]
  putStrLn $ show params
