package com.ardublock.translator.block.lifeplanters;

import com.ardublock.translator.Translator;
import com.ardublock.translator.block.TranslatorBlock;
import com.ardublock.translator.block.exception.SocketNullException;
import com.ardublock.translator.block.exception.SubroutineNotDeclaredException;

public class lp_setlight extends TranslatorBlock
{

	public lp_setlight(Long blockId, Translator translator, String codePrefix, String codeSuffix, String label)
	{
		super(blockId, translator, codePrefix, codeSuffix, label);
	}

	@Override
	public String toCode() throws SocketNullException, SubroutineNotDeclaredException
	{
		String name;
		String intensity;
		TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
		name = translatorBlock.toCode();
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(1);
		intensity = translatorBlock.toCode();
		
		return ("planter" + name + ".setLightIntensity("+intensity+");");
	}
	
}
