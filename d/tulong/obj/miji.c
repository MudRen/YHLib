inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(CYN "����ʮ��������" NOR, ({ "xianglong miji", "book", "miji"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long",
        "�˴�����������д��������ؤ��ľ�ѧ����ʮ���ơ�\n"
        "Ϊ�����������ϵ���ѧ��\n", );
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 

        if (!(arg=="xianglong miji" || arg == "book" || arg == "miji" ))
        return 0;
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        message("vision", me->name() + "��ר�ĵ��ж�����ʮ�������š�\n", environment(me), me);
        if( (int)me->query("jing") < 80 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if( (int)me->query("qi") < 80 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        pxlevel = me->query_skill("dragon-strike", 1);
        if( (int)me->query("combat_exp") < 100000 ) {
                write("���ʵս���鲻�㣬�޷���������ʮ���������е����ݡ�\n");
                return 1;
        }
        if( (int)me->query("dragon-strike") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("���ʵս���鲻�㣬�޷���������ʮ���������е����ݡ�\n");
                return 1;
        }
        if( me->query_skill("dragon-strike", 1) > 249){
                write("���ж���һ��������Ƿ��������е����ݶ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }
        if( me->query_skill("dragon-strike", 1) < 80){
                write("���ж���һ��������Ƿ��������е���������ޱȣ�û��ѧ���κζ�����\n");
                return 1;
        }
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->improve_skill("dragon-strike", (int)me->query_skill("literate", 1)/5+1);
        write("����ϸ�ж�����ʮ�������ţ������ĵá�\n");
        return 1;
}

