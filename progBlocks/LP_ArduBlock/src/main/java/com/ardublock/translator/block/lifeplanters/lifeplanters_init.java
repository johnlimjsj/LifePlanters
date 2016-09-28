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
			String name;
			String addr;
			String pump_Pin, light_Pin, feeder_Pin;
			
			TranslatorBlock translatorBlock = this.getRequiredTranslatorBlockAtSocket(0);
			name = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(1);
			addr = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(2);
			pump_Pin = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(3);
			light_Pin = translatorBlock.toCode();
			translatorBlock = this.getRequiredTranslatorBlockAtSocket(4);
			feeder_Pin = translatorBlock.toCode();
			
			translator.addHeaderFile("Wire.h");
			translator.addHeaderFile("LifePlanters.h");
			translator.addDefinitionCommand("LifePlanters planter"+name+"("+addr+", " + pump_Pin + ", " + light_Pin + ", " + feeder_Pin +" );");
			translator.addSetupCommand("Wire.begin();\n" +
			"Serial.begin(9600);");
			
			
			return "" ;	

		}
}
