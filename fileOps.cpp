//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "fileOps.h"
#include "actionHandler.h"
#include <QXmlStreamWriter>

void createAndSaveCurrentToFile(QFile* file, actionHandler* handler)
{
	if (file->exists()) handler->nonFatalErrorEncountered("File already exists",	//check that the file name supplied is valid
		"The file with the name you are attempting to enter already exists. Please create a file with a different name or location");

	file->open(QIODevice::WriteOnly);

	QXmlStreamWriter fileStream(file);
	fileStream.setAutoFormatting(true);

	fileStream.writeStartDocument("1.0");
	fileStream.writeStartElement("document");

	fileStream.writeStartElement("sysCon");	//add the system constant to the file
	fileStream.writeCharacters(QString::number(DEFSYSCON));
	fileStream.writeEndElement();

	fileStream.writeStartElement("teamSet");	//add all teams in the teamset to the file
	fileStream.writeAttribute("numTeams", QString::number((*(handler->teamSet.get()))->teamSet.size()));
	for (size_t i = 0; i < (*(handler->teamSet.get()))->teamSet.size(); i++) {
		fileStream.writeStartElement("team");
		fileStream.writeStartElement("name");	//write the teams name
		fileStream.writeCharacters(QString::fromUtf8((*(handler->teamSet.get()))->teamSet[i].name));
		fileStream.writeEndElement();
		
		fileStream.writeStartElement("rating"); //write the teams rating
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].rating));
		fileStream.writeEndElement();

		fileStream.writeStartElement("RD");	//write the teams RD
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].RD));
		fileStream.writeEndElement();

		fileStream.writeStartElement("volatility");	//write the teams RD
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].volatility));
		fileStream.writeEndElement();

		fileStream.writeStartElement("matchesWon"); //write the number of matches the team has won
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].matchWonCount));
		fileStream.writeEndElement();

		fileStream.writeStartElement("matchesLost"); //write the number of matches the team has lost
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].matchLostCount));
		fileStream.writeEndElement();

		fileStream.writeStartElement("MatchesDrawn"); //write the number of matches the team has drawn
		fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].matchDrawnCount));
		fileStream.writeEndElement();

		fileStream.writeStartElement("ratingHistory"); //write the rating history of the team
		fileStream.writeAttribute("histSize", QString::number((*(handler->teamSet.get()))->teamSet[i].rateHist.size()));
		for (size_t x = 0; x < (*(handler->teamSet.get()))->teamSet[i].rateHist.size(); x++) {
			fileStream.writeStartElement("rating");
			fileStream.writeCharacters(QString::number((*(handler->teamSet.get()))->teamSet[i].rateHist[x]));
			fileStream.writeEndElement();
		}
		fileStream.writeEndElement();
		fileStream.writeEndElement();
	}
	fileStream.writeEndElement();
	fileStream.writeEndDocument();

	file->close();
}

void readFromFile(QFile* file, actionHandler* handler)
{
	glicko2TeamSet newTeamSet;
	if(!file->exists()) handler->nonFatalErrorEncountered("File already exists",	//check that the file name supplied is valid
		"The file with the name you are attempting to enter already exists. Please create a file with a different name or location");

	file->open(QIODevice::ReadOnly);
	QXmlStreamReader fileStream(file);
	while (!fileStream.atEnd()) {
		QXmlStreamReader::TokenType comp = fileStream.readNext();
		QString test = fileStream.errorString();
		switch (comp) {
		case QXmlStreamReader::StartElement:
			if (fileStream.name().toString() == "sysCon\0") {
				newTeamSet.sysCon = fileStream.readElementText().toFloat();
			}
			else if (fileStream.name().toString() == "teamSet\0") {
				int numTeams = fileStream.attributes().value("numTeams").toInt();
				newTeamSet.teamSet.reserve(numTeams);
				for (int i = 0; i < numTeams; i++) {
					fileStream.readNextStartElement();
					fileStream.readNextStartElement();
					std::string testString = fileStream.name().toString().toStdString();
					std::string tempName = fileStream.readElementText().toStdString();
					fileStream.readNextStartElement();
					float tempRating = fileStream.readElementText().toFloat();
					fileStream.readNextStartElement();
					float tempRD = fileStream.readElementText().toFloat();
					fileStream.readNextStartElement();
					float tempVol = fileStream.readElementText().toFloat();
					fileStream.readNextStartElement();
					int matchesWon = fileStream.readElementText().toInt();
					fileStream.readNextStartElement();
					int matchesLost = fileStream.readElementText().toInt();
					fileStream.readNextStartElement();
					int matchesDrawn = fileStream.readElementText().toInt();
					fileStream.readNextStartElement();

					team temp(tempName, tempRating, tempRD);

					std::vector<float> rateHistTemp;
					size_t histSize = fileStream.attributes().value("histSize").toInt();
					for (size_t x = 0; x < histSize; x++) {
						fileStream.readNextStartElement();
						rateHistTemp.push_back(fileStream.readElementText().toFloat());
						temp.addGraphVal();
					}
					temp.volatility = tempVol;
					temp.matchWonCount = matchesWon;
					temp.matchDrawnCount = matchesDrawn;
					temp.matchLostCount = matchesLost;
					temp.rateHist = rateHistTemp;
					newTeamSet.teamSet.push_back(temp);
					fileStream.readNextStartElement();
					fileStream.readNextStartElement();
				}
			}
		}

	}
	(*(handler->teamSet))->teamSet = newTeamSet.teamSet;
	(*(handler->teamSet))->sysCon = newTeamSet.sysCon;
}
