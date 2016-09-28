package com.ardublock.translator.block.lifeplanters;

import com.ardublock.translator.Translator;
import com.ardublock.translator.block.TranslatorBlock;
import com.ardublock.translator.block.exception.SocketNullException;
import com.ardublock.translator.block.exception.SubroutineNotDeclaredException;

public class lp_pump extends TranslatorBlock
{

	public lp_pump(Long blockId, Translator translator, String codePrefix, String codeSuffix, String label)
	{
		super(blockId, translator, codePrefix, codeSuffix, label);
	}

	@Override
	public String toCode() throws SocketNullException, SubroutineNotDeclaredException
	{
		String name;
		String state;
		TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
		name = translatorBlock.toCode();
		translatorBlock = this.getRequiredTranslatorBlockAtSocket(1);
		state = translatorBlock.toCode();
		
		return ("planter" + name + ".setPumpState("+state+");");
	}
	
}
