# { id : [name, ratings_sum, ratings_count]}   ratings_sum/ratings_count

# Load the movie ids and titles and prepare the dictionary.
#
movie_file = open('movie-names.txt', 'r')
#creates the list
movie_ratings = {}

for line in movie_file:
    #splits the values from the spaces
    values = line.split()
    #Movie id is the numver movie slot it is on
    movie_id = int(values[0])

    #creates the movie string
    movie_title = ''
    #it starts at value 1 instead of the string of 0
    for v in range(1, len(values)):
        movie_title += (values[v] + ' ')
    movie_ratings[movie_id] = [movie_title, 0, 0]

movie_file.close()



# Load the movie ids and ratings and update the dictionary
#
ratings_file = open('movies-ratings.txt', 'r')

for line in ratings_file:
    #splits based on spaces
    values = line.split()
    #first value
    movie_id = int(values[0])
    #value 2
    movie_rating = int(values[1])
    #first the name is in position 1
    #2nd is the movie id
    #third is the movie rating
    movie_ratings[movie_id] = [movie_ratings[movie_id][0], \
                               movie_ratings[movie_id][1] + movie_rating, \
                               movie_ratings[movie_id][2] + 1]

ratings_file.close()


# Output the HTML table
#
html_file = open('movies.html', 'w')

movie_info = movie_ratings.values()

movie_info = sorted(movie_info, key = lambda x : x[1]/x[2], reverse = True)

html_file.write('<html>\n')
html_file.write('<head>\n')
html_file.write('  <title>Movie Ratings</title>\n')
html_file.write('</head>\n')
html_file.write('<body>\n')
html_file.write('  <table>\n')
html_file.write('    <tr style="text-align:left">\n')
html_file.write('      <th>Title</th>\n')
html_file.write('      <th>Rating</th>\n')
html_file.write('      <th># of Ratings</th>\n')
html_file.write('    </tr>\n')

for info in movie_info:

    html_file.write('    <tr>\n')
    html_file.write('      <td>' + info[0] + '</td>\n')
    html_file.write('      <td>' + str(info[1]/info[2]) + '</td>\n')
    html_file.write('      <td>' + str(info[2]) + '</td>\n')
    html_file.write('    </tr>\n')


html_file.write('  </table>\n')
html_file.write('</body>\n')
html_file.write('</html>\n')
