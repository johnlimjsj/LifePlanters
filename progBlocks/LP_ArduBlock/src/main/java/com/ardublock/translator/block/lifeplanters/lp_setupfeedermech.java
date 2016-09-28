package com.ardublock.translator.block.lifeplanters;

import com.ardublock.translator.Translator;
import com.ardublock.translator.block.TranslatorBlock;
import com.ardublock.translator.block.exception.SocketNullException;
import com.ardublock.translator.block.exception.SubroutineNotDeclaredException;

public class lp_setupfeedermech extends TranslatorBlock
{

	public lp_setupfeedermech(Long blockId, Translator translator, String codePrefix, String codeSuffix, String label)
	{
		super(blockId, translator, codePrefix, codeSuffix, label);
	}

	@Override
	public String toCode() throws SocketNullException, SubroutineNotDeclaredException
	{
		String name, fullName;
		String nofeedPosition, feedPosition, feedDuration; 
		String moveDuration;
		TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
		name = translatorBlock.toCode();
		fullName = "planter" + name;
		
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(1);
		nofeedPosition = translatorBlock.toCode();
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(2);
		feedPosition = translatorBlock.toCode();
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(3);
		feedDuration = translatorBlock.toCode();
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(4);
		moveDuration = translatorBlock.toCode();
		
		translator.addSetupCommand(fullName + ".set_nofeed_position("+ nofeedPosition + ");\n"
								+ fullName + ".set_feed_position("+ feedPosition + ");\n"
								+ fullName + ".set_feed_duration("+ feedDuration + ");\n"
								+ fullName + ".calibrate_servoMoveDuration("+ moveDuration + ");\n"
								+ "");
		return "";
	}
	
}
