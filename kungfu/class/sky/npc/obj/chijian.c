#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR "�ལ" NOR, ({ "chi jian" , "jian" , "sword", "chi", "chijian" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ���ĳ������ĳ�������������ʺ�ɫ��\n" NOR);
                set("value", 200000);
                set("rigidity", 8000);   
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "�ӱ������ལ����ʱ����һ��������ɱ����\n" NOR);
                set("unwield_msg", HIR "$N" HIR "̾�˿��������ལ��ر���\n" NOR);
        }
        init_sword(250);
        setup();
}

