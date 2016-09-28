package com.ardublock.translator.block.lifeplanters;

import com.ardublock.translator.Translator;
import com.ardublock.translator.block.TranslatorBlock;
import com.ardublock.translator.block.exception.SocketNullException;
import com.ardublock.translator.block.exception.SubroutineNotDeclaredException;

public class lp_printmoisture extends TranslatorBlock
{

	public lp_printmoisture(Long blockId, Translator translator, String codePrefix, String codeSuffix, String label)
	{
		super(blockId, translator, codePrefix, codeSuffix, label);
	}

	@Override
	public String toCode() throws SocketNullException, SubroutineNotDeclaredException
	{
		String addr;
		TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
		addr = translatorBlock.toCode();
		return ("planter" + addr + ".printScaledMoisture();");
	}
	
}
