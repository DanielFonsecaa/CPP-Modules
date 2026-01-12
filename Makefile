CPP_DIRS := cpp00 cpp01 cpp02 cpp03 cpp04 cpp05 cpp06 cpp07 cpp08 cpp09

.PHONY: all clean fclean re

fclean:
	@for dir in $(CPP_DIRS); do \
		for ex in $$dir/ex*; do \
			if [ -f $$ex/Makefile ]; then \
				echo "→ fclean in $$ex"; \
				make -C $$ex fclean; \
			fi; \
		done; \
	done
