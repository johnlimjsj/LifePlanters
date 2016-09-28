package com.ardublock.translator.block.lifeplanters;

import com.ardublock.translator.Translator;
import com.ardublock.translator.block.TranslatorBlock;
import com.ardublock.translator.block.exception.SocketNullException;
import com.ardublock.translator.block.exception.SubroutineNotDeclaredException;

public class lifeplanters_init  extends TranslatorBlock {

	public lifeplanters_init (Long blockId, Translator translator, String codePrefix, String codeSuffix, String label)
	{
		super(blockId, translator, codePrefix, codeSuffix, label);
	}
	
	//@Override
		public String toCode() throws SocketNullException, SubroutineNotDeclaredException
		{
			String addr ;
			String motorPin;
			String ledPin;

			TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
			addr = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(1);
			motorPin = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(2);
			ledPin = translatorBlock.toCode();
			
			translator.addHeaderFile("Wire.h");
			translator.addHeaderFile("LifePlanters.h");
			translator.addDefinitionCommand("LifePlanters planter"+addr+"("+addr+", "+motorPin+", "+ledPin);
			translator.addSetupCommand("Wire.begin();\n" +
			"Serial.begin();");
			
			
			return "" ;	
		}
}
