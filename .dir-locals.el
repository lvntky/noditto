;; .dir-locals.el
((nil . ((eval . (let ((root (locate-dominating-file default-directory ".dir-locals.el")))
                   (setq flycheck-clang-include-path
                         (list (expand-file-name "include" root)
                               (expand-file-name "include/noditto" root)
                               (expand-file-name "include/noditto/commons" root)
                               (expand-file-name "include/noditto/lexer" root)
                               (expand-file-name "include/noditto/tostring" root))))))))

