# This function takes a string consisting of the characters s, d, t, h, and I, where
#
#    s : represents a single
#    d : represents a double
#    t : represents a triple
#    h : represents a home run
#    I : a change of at-bats (the end of a half-inning)
#
# and return a tuple of the form (away, home) where
#
#    away : the away team's score (assumed to be at bat first)
#    home : the home team's score
#
# an example input string would look like
#
#    ssdstIsssItdtssIdhts
#
# This function would then return (7, 3).
#
# The assumption made by this function is that all runners move the same number of
# bases as the batter. For example, if there are runners on first and second and 
# the batter gets a double, the runner on second goes home (scores), the runner on 
# first goes to third and the batter ends up on second.
#
def get_scores(inning_info):
    
    # Initialize the values to be returned to the caller.
    #
    away = 0
    home = 0

    # We assume the away team is up first.
    #
    is_away = True

    # Set the bases up: Each base, except home, is represented by a boolean. True means a
    # runner is on the base and False means the base is empty.
    #
    # runs represents home and accumulates the score over the at-bat.
    #
    first  = False
    second = False
    third  = False
    runs   = 0


    # Process the string letter by letter.
    #
    for token in inning_info:

        # If we are switching innings, accumulate the appropriate score (away or home) and
        # rest the bases for a new inning.
        #
        if token == 'I':

            if is_away:

                away += runs

            else:

                home += runs

            first  = False
            second = False
            third  = False
            runs   = 0

            is_away =  not is_away
        
        # If a single, move third to home (scoring), second to third, first to second and
        # place the batter on first.
        #
        elif token == 's':

            if third:

                third = False

                runs += 1

            if second:

                second = False

                third = True

            if first:

                first = False

                second = True

            first = True

        # If a double, move third and second to home (scoring), first to third and
        # place the batter on second.
        #
        elif token == 'd':

            if third:

                third = False

                runs += 1

            if second:

                second = False

                runs += 1

            if first:

                first = False

                third = True

            second = True

        # If a triple, move third, second, and first to home (scoring) and
        # place the batter on third.
        #
        elif token == 't':

            if third:

                third = False

                runs += 1

            if second:

                second = False

                runs += 1

            if first:

                first = False

                runs += 1

            third = True

        # If a home run, move any runner on the bases and the batter to home (scoring).
        #
        elif token == 'h':

            if third:

                third = False

                runs += 1

            if second:

                second = False

                runs += 1

            if first:

                first = False

                runs += 1

            runs += 1
        
        # Let the user know if we encounter an unexpected character along the way.
        #  
        else:

            print('Unknown character')
        

    # Process the runs for the last half of the inning. (Since the inningInfo string 
    # doesn't necessarily end in an I, we have to process the runs scored one last time.)
    #
    if is_away:

        away += runs

    else:

        home += runs


    
    return (away, home)





# Test the function:
#
inning_info = input('Enter the inning information: ')

scores = get_scores(inning_info)

print('The end score is Away: ' + str(scores[0]) + ', Home: ' + str(scores[1]) + '.')