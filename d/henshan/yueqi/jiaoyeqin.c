#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(HIY "��Ҷ���١�����" NOR, ({ "jiaoye qin", "jiaoye", "qin" }));
        set_weight(700);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
  			    
                set("long", HIY "�����˺��μξ����������ټ�ף��������\n"
				"���������ݣ���Ҷ��߹�����������ɫ��\n"
				"��͸����Ϊ�������ѵ�һ������Ʒ��\n" NOR);
		set("value", 800000);
		set("material", "wood");
	     }
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
