// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( "����Ʒ" ,({ "jinian pin", "jinin", "pin" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bamboo");
                set("long", "���ﻭ�š����������糤����������û�¸ɡ����(wfoxd)��
���Կ�����Ӣ������������������������棬��Ŀ���ʣ�ò���˰���\n" );
                set("wield_msg", "$N�������������ó�һ��$n��������������С�\n" );
                set("unequip_msg","$N����İ�$n�� �����䡣\n" );
        }
        init_sword(1);
        setup();
}

