/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// constructors
Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	ideas[0] = "Build a nest";
	ideas[1] = "Hunt for food";
	ideas[2] = "Migrate to a warmer climate";
	ideas[3] = "Establish dominance in the pack";
	ideas[4] = "Form a social bond";
	ideas[5] = "Hide from predators";
	ideas[6] = "Mark territory";
	ideas[7] = "Find a mate";
	ideas[8] = "Search for water";
	ideas[9] = "Play with other members";
	ideas[10] = "Take a nap";
	ideas[11] = "Groom themselves or others";
	ideas[12] = "Explore their environment";
	ideas[13] = "Use tools to extract food";
	ideas[14] = "Communicate with gestures or sounds";
	ideas[15] = "Protect their offspring";
	ideas[16] = "Look for a suitable burrow or den";
	ideas[17] = "Collect materials for shelter";
	ideas[18] = "Learn a new skill";
	ideas[19] = "Adapt to changes in the surroundings";
	ideas[20] = "Collaborate in a group hunt";
	ideas[21] = "Form a defensive formation";
	ideas[22] = "Use camouflage to avoid predators";
	ideas[23] = "Mimic the appearance of a dangerous animal";
	ideas[24] = "Forage for fruits or nuts";
	ideas[25] = "Create a diversion to confuse enemies";
	ideas[26] = "Bask in the sun to regulate body temperature";
	ideas[27] = "Investigate a new and unfamiliar object";
	ideas[28] = "Engage in a mating display";
	ideas[29] = "Burrow into the ground for safety";
	ideas[30] = "Take turns caring for young ones";
	ideas[31] = "Synchronize movements with the group";
	ideas[32] = "Use echolocation to find prey";
	ideas[33] = "Hibernate during the winter months";
	ideas[34] = "Follow a specific migration route";
	ideas[35] = "Form a coalition to increase hunting success";
	ideas[36] = "Search for a source of fresh water";
	ideas[37] = "Participate in a courtship dance";
	ideas[38] = "Retrieve hidden food reserves";
	ideas[39] = "Imitate the sounds of other animals";
	ideas[40] = "Practice flying or swimming skills";
	ideas[41] = "Create a distraction to escape from a predator";
	ideas[42] = "Sharpen claws or teeth";
	ideas[43] = "Gather leaves or grass for a nest";
	ideas[44] = "Engage in mutual grooming";
	ideas[45] = "Perform a territorial display";
	ideas[46] = "Initiate a game with another animal";
	ideas[47] = "Follow the leader of the group";
	ideas[48] = "Release a warning signal to alert others of danger";
	ideas[49] = "Adopt a different feeding strategy";
	ideas[50] = "Call out to attract a mate or group members";
	ideas[51] = "Bury or cache excess food for later consumption";
	ideas[52] = "Form an alliance with another group";
	ideas[53] = "Create a diversion to protect young ones";
	ideas[54] = "Climb to higher ground for a better vantage point";
	ideas[55] = "Use vocalizations to coordinate movement";
	ideas[56] = "Dig a burrow or tunnel for shelter";
	ideas[57] = "Adjust sleep patterns to match environmental changes";
	ideas[58] = "Engage in play-fighting to practice skills";
	ideas[59] = "Mark trails with scent for navigation";
	ideas[60] = "Form a grooming chain within a group";
	ideas[61] = "Rotate grazing areas to allow vegetation to regrow";
	ideas[62] = "Show submission to establish harmony in the group";
	ideas[63] = "Collect and store objects for future use";
	ideas[64] = "Learn and imitate the behaviors of other species";
	ideas[65] = "Initiate a mating dance or ritual";
	ideas[66] = "Create a shelter using leaves or branches";
	ideas[67] = "Conserve energy by resting in a shady area";
	ideas[68] = "Communicate through scent markings";
	ideas[69] = "Play a game of chase or tag";
	ideas[70] = "Reinforce social bonds through grooming";
	ideas[71] = "Swarm together for protection against predators";
	ideas[72] = "Scavenge for food scraps left by other animals";
	ideas[73] = "Form a defensive circle around vulnerable individuals";
	ideas[74] = "Collect materials for a mating display area";
	ideas[75] = "Create a visual signal to communicate with distant members";
	ideas[76] = "Roll in mud or water to cool down in hot weather";
	ideas[77] = "Use body language to convey intentions";
	ideas[78] = "Adjust daily routines based on the phases of the moon";
	ideas[79] = "Initiate a group howl, roar, or song";
	ideas[80] = "Form a line to move through tall grass or vegetation";
	ideas[81] = "Collect and store water in natural containers";
	ideas[82] = "Construct a barrier to protect against predators";
	ideas[83] = "Practice agility and balance by climbing trees";
	ideas[84] = "Create a distraction to lead predators away from young ones";
	ideas[85] = "Form a chain to help weaker members cross difficult terrain";
	ideas[86] = "Borrow tactics from other species for hunting";
	ideas[87] = "Use tail movements to communicate emotions";
	ideas[88] = "Roll into a ball or play dead to avoid danger";
	ideas[89] = "Form a stampede to confuse predators";
	ideas[90] = "Blend into the surroundings using natural colors";
	ideas[91] = "Take turns keeping watch for potential threats";
	ideas[92] = "Reenact confrontations to establish dominance";
	ideas[93] = "Form a synchronized swimming or flying pattern";
	ideas[94] = "Playfully interact with other species";
	ideas[95] = "Use environmental elements for artistic displays";
	ideas[96] = "Create a decoy nest to mislead predators";
	ideas[97] = "Initiate a group grooming session";
	ideas[98] = "Share food with other members in an act of kindness";
	ideas[99] = "Gather in a circle for communal rest or sleep";}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor called\n";
}

Brain &Brain::operator=(const Brain &other)
{
	int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
	std::cout << "Brain copy assignment constructor called\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called\n";
}
