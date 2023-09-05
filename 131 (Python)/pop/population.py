def import_data(filepath):

    in_file = open(filepath, 'r')

    state_populations = {}

    for line in in_file:

        values = line.split(',')

        state = values[0]

        population = int(values[2])

        state_populations[state] = population
    

    in_file.close()

    return state_populations


def export_min_max_average(filepath, state_populations):

    out_file = open(filepath, 'w')

    min_population = 1000000000
    max_population = 0

    total_population = 0

    for state in state_populations:

        if min_population > state_populations[state]:

            min_population = state_populations[state]
            min_state = state
    
        if max_population < state_populations[state]:

            max_population = state_populations[state]
            max_state = state
        
        total_population += state_populations[state]
    
    out_file.write("Min: " + min_state + " - " + str(min_population) )
    out_file.write("Max: " + max_state + " - " + str(max_population)+ '\n')
    out_file.write("Avg: " + str(total_population / len(state_populations)) + '\n')

        

s_p = import_data('population-in.txt')
export_min_max_average('population-out.txt', s_p)
