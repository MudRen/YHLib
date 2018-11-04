#include <ansi.h>; 
inherit ITEM;

void create()
{
        set_name(HIW "�������澭��" NOR, ({ "jiuyin zhenjing", "jiuyin", "zhenjing"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", HIW "����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С������澭����\n"
                                "�֡���Ƥ���ƣ������Ѿ�����ܾ��ˡ��澭�м����д�\n"
                                "���ơ������׹�צ�����ħȭ�������޷����׽�͹Ǻ�\n"
                                "�����귭�Ⱦ�������������Ŷ���(read)����\n" NOR, );
        }
}

void init()
{
        add_action("do_du", "yanjiu");
        add_action("do_du", "research");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        string skill, book;
        int lv;

        if(! arg)
        {
                write("�о������澭��ָ���ʽ��\n"
                      "research|yanjiu <����> from <�����澭>\n");
                return 1;
        }
        if(arg == "yijin-duangu" || arg == "shexing-lifan"  
        || arg == "cuixin-zhang" || arg == "jiuyin-baiguzhao" 
        || arg == "jiuyin zhenjing" || arg == "zhenjing" )
        {
                write("�о������澭��ָ���ʽ��\n"
                      "research|yanjiu <����> from <�����澭>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", skill, book) != 2)
        return 0;
        if( me->is_busy())
        {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting())
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
        if( ! me->query_skill("literate", 1) )
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        if (! id(book))
        {
                write("����û���Ȿ�顣\n");
                return 1;
        }
        if ( skill != "yijin-duangu" && skill != "shexing-lifan"  
          && skill != "cuixin-zhang" && skill != "jiuyin-baiguzhao" )
        {
                write(HIW "����ԴӾ����澭���о����׽�͹ǣ�yijin-duangu���������귭��shexing-lifan����\n"
                          "�����ƣ�cuixin-zhang���Լ������׹�צ��jiuyin-baiguzhao����\n\n" NOR,);
                return 1;
        }
        if( me->query_skill("sanscrit", 1) < 199)
        {
                write("�������ˮƽ̫�ͣ��޷������澭�������ص����ݡ�\n");        
                return 1;
        }
        if( (int)me->query("combat_exp") < 500000 )
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
        if( (int)me->query("jing") < 101 || (int)me->query("qi") < 101 )
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if ( skill == "yijin-duangu" )
        {
                lv = me->query_skill("yijin-duangu", 1);
                if( (int)me->query("combat_exp") < (int)lv * lv * lv/10 ) {
                        write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                        return 1;
                }
                if( lv > 199) {
                        write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                        return 1;
                }
                message("vision", me->name() + "��ר�ĵ��ж������澭��\n", environment(me), me);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                me->improve_skill("yijin-duangu", me->query("int")/4+1);
                write("����ϸ�ж������澭�����澭�������ص��׽�͹������ĵá�\n");
                return 1;
        }
        if ( skill == "shexing-lifan" )
        {
                lv = me->query_skill("shexing-lifan", 1);
                if( (int)me->query("combat_exp") < (int)lv * lv * lv/10 ) {
                        write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                        return 1;
                }
                if( lv > 199) {
                        write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                        return 1;
                }
                message("vision", me->name() + "��ר�ĵ��ж������澭��\n", environment(me), me);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                me->improve_skill("shexing-lifan", me->query("int")/4+1);
                write("����ϸ�ж������澭�����澭�������ص������귭�Ṧ�����ĵá�\n");
                return 1;
        }
        if ( skill == "cuixin-zhang" )
        {
                lv = me->query_skill("cuixin-zhang", 1);
                if( (int)me->query("combat_exp") < (int)lv * lv * lv/10 ) {
                        write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                        return 1;
                }
                if( lv > 199) {
                        write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                        return 1;
                }
                message("vision", me->name() + "��ר�ĵ��ж������澭��\n", environment(me), me);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                me->improve_skill("cuixin-zhang", me->query("int")/4+1);
                write("����ϸ�ж������澭�����澭�������صĴ����������ĵá�\n");
                return 1;
        }
        if ( skill == "jiuyin-baiguzhao" )
        {
                lv = me->query_skill("jiuyin-baiguzhao", 1);
                if( (int)me->query("combat_exp") < (int)lv * lv * lv/10 ) {
                        write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                        return 1;
                }
                if( lv > 199) {
                        write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                        return 1;
                }
                message("vision", me->name() + "��ר�ĵ��ж������澭��\n", environment(me), me);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                me->improve_skill("jiuyin-baiguzhao", me->query("int")/4+1);
                write("����ϸ�ж������澭�����澭�������صľ����׹�צ�����ĵá�\n");
                return 1;
        }
}


