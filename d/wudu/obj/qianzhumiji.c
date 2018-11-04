inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}

void init()
{
        add_action("do_yanjiu", "yanjiu");
        add_action("do_yanjiu", "research");
        add_action("do_du", "du");
}

void create()
{
        set_name(WHT "ǧ��������ܸ" NOR, ({ "qianzhu miji", "miji", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", WHT
        "����ʧ���Ѿõ�ǧ��������ܸ�°벿������Դ����о�һЩǧ�����ֵľ��С�\n\n" NOR, );
        }
}

int do_du(string arg)
{
        string dir;

        if( ! arg || arg == "" ) return 0;

        if( arg == "miji" || arg == "qianzhu miji" || arg == "book" )
        {
                write(HIY "\n��ܸ������˲���ǧ�����ֵľ������ţ�����������о��о���\n" NOR);
                return 1;
        }
}

int do_yanjiu(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        string skill, book;
        int lv;

        if(! arg)
        {
                write("�о�ǧ��������ָܸ���ʽ��\n"
                      "research|yanjiu <����> from <ǧ��������ܸ>\n");
                return 1;
        }
        if(arg == "suck"  || arg == "wan"  
        || arg == "zhugu" || arg == "miji" 
        || arg == "book"  || arg == "qianzhu miji" )
        {
                write("�о�ǧ��������ָܸ���ʽ��\n"
                      "research|yanjiu <����> from <ǧ��������ܸ>\n");
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

        if ( skill != "suck"
          && skill != "zhugu"  
          && skill != "wan" )
        {
                write(WHT "����Դ�ǧ��������ܸ���о�������������"
                      "�ţ�suck������ƾ���zhugu���Լ���������"
                      "����wan����\n\n" NOR,);
                return 1;
        }

        if( (int)me->query("jing") < 50 || (int)me->query("qi") < 50 )
        {
                write("�����ڹ���ƣ�룬�޷�ר���ж���\n");
                return 1;
        }

        if ( skill == "suck" )
        {
                if (me->query("can_perform/qianzhu-wandushou/suck"))
                {
                        write("���Ѿ�ѧ����ǧ���������������š�\n");
                        return 1;
                }

                if (me->query("potential") < 1)
                {
                        write("���ж���һ����������е��Ժ����������Լ���Ǳ�ܲ����ˡ�\n");
                        return 1;
                }

                message("vision", me->name() + "��ר�ĵ��ж�ǧ��������ܸ��\n", environment(me), me);
                tell_object(me, "\n����ϸ���ж�ǧ��������ܸ����������һ�½ڡ�\n");
                me->receive_damage("qi", 30);
                me->receive_damage("jing", 30);
                me->add("potential", -1);
                remove_call_out("suck"); 
                call_out("suck", 1, me);
                me->start_busy(2);
                return 1;
        }

        if ( skill == "zhugu" )
        {
                if (me->query("can_perform/qianzhu-wandushou/zhugu"))
                {
                        write("���Ѿ�ѧ���ˡ���ƾ�����һ�С�\n");
                        return 1;
                }

                if (me->query("potential") < 1)
                {
                        write("���ж���һ����������е��Ժ����������Լ���Ǳ�ܲ����ˡ�\n");
                        return 1;
                }

                message("vision", me->name() + "��ר�ĵ��ж�ǧ��������ܸ��\n", environment(me), me);
                tell_object(me, "\n����ϸ���ж�ǧ��������ܸ��ƾ���һ�½ڡ�\n");
                me->receive_damage("qi", 30);
                me->receive_damage("jing", 30);
                me->add("potential", -1);
                remove_call_out("zhugu"); 
                call_out("zhugu", 1, me);
                me->start_busy(2);
                return 1;
        }

        if ( skill == "wan" )
        {
                if (me->query("can_perform/qianzhu-wandushou/wan"))
                {
                        write("���Ѿ�ѧ���ˡ�������졹��һ�С�\n");
                        return 1;
                }

                if (me->query("potential") < 1)
                {
                        write("���ж���һ����������е��Ժ����������Լ���Ǳ�ܲ����ˡ�\n");
                        return 1;
                }

                message("vision", me->name() + "��ר�ĵ��ж�ǧ��������ܸ��\n", environment(me), me);
                tell_object(me, "\n����ϸ���ж�ǧ��������ܸ���������һ�½ڡ�\n");
                me->receive_damage("qi", 30);
                me->receive_damage("jing", 30);
                me->add("potential", -1);
                remove_call_out("wan"); 
                call_out("wan", 1, me);
                me->start_busy(2);
                return 1;
        }
}

int suck(object me)
{
        if( (int)me->query_skill("qianzhu-wandushou", 1) < 100)
        {
                write(HIC "���ж��˰��죬�����Լ���ǧ���������򲻹����޷�ѧ�����������š�\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("hand", 1) < 100)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����ַ����򲻹����޷�ѧ�����������š�\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("poison", 1) < 100)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����������򲻹����޷�ѧ�����������š�\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("force") < 150)
        {
                write(HIC "���ж��˰��죬�����Լ����ڹ����̫ǳ���޷�ѧ�����������š�\n" NOR);
                return 1;
        }

        if (me->query("max_neili") < 1000)
        {
                write(HIC "���ж��˰��죬�����Լ���������Ϊ̫ǳ���޷�ѧ�����������š�\n" NOR);
                return 1;
        }

        if (random(100) > 5)
        {
                write(HIY "������������������򣬵����ǲ�����̣�������������ж����С�\n" NOR);
                return 1;
        }
   else { 
                me->improve_skill("qianzhu-wandushou", 5000000);
                me->improve_skill("poison", 5000000);
                me->set("can_perform/qianzhu-wandushou/suck", 1);
                tell_object(me, HIC "��ѧ�����������ǧ����������������\n" NOR);
                write(HIW "\n����ϸ�ж�ǧ��������ܸ�����������������������������ڡ�\n" NOR);
                return 1;
        }
}

int zhugu(object me)
{
        if( (int)me->query_skill("qianzhu-wandushou", 1) < 130)
        {
                write(HIC "���ж��˰��죬�����Լ���ǧ���������򲻹����޷�ѧ����ƾ���\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("hand", 1) < 130)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����ַ����򲻹����޷�ѧ����ƾ���\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("poison", 1) < 130)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����������򲻹����޷�ѧ����ƾ���\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("force") < 200)
        {
                write(HIC "���ж��˰��죬�����Լ����ڹ����̫ǳ���޷�ѧ����ƾ���\n" NOR);
                return 1;
        }

        if (me->query("max_neili") < 1500)
        {
                write(HIC "���ж��˰��죬�����Լ���������Ϊ̫ǳ���޷�ѧ����ƾ���\n" NOR);
                return 1;
        }

        if (random(150) > 5)
        {
                write(HIY "�����ƾ��������򣬵����ǲ�����̣�������������ж����С�\n" NOR);
                return 1;
        }
   else { 
                me->improve_skill("qianzhu-wandushou", 5000000);
                me->improve_skill("poison", 5000000);
                me->set("can_perform/qianzhu-wandushou/zhugu", 1);
                tell_object(me, HIC "��ѧ���ˡ���ƾ�����һ�С�\n" NOR);
                write(HIW "\n����ϸ�ж�ǧ��������ܸ��������������ƾ����������ڡ�\n" NOR);
                return 1;
        }
}

int wan(object me)
{
        if( (int)me->query_skill("qianzhu-wandushou", 1) < 220)
        {
                write(HIC "���ж��˰��죬�����Լ���ǧ���������򲻹����޷�ѧ��������졣\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("hand", 1) < 220)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����ַ����򲻹����޷�ѧ��������졣\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("poison", 1) < 200)
        {
                write(HIC "���ж��˰��죬�����Լ��Ի����������򲻹����޷�ѧ��������졣\n" NOR);
                return 1;
        }

        if( (int)me->query_skill("force") < 300)
        {
                write(HIC "���ж��˰��죬�����Լ����ڹ����̫ǳ���޷�ѧ��������졣\n" NOR);
                return 1;
        }

        if (me->query("max_neili") < 3500)
        {
                write(HIC "���ж��˰��죬�����Լ���������Ϊ̫ǳ���޷�ѧ��������졣\n" NOR);
                return 1;
        }

        if (random(200) > 5)
        {
                write(HIY "�����������������򣬵����ǲ�����̣�������������ж����С�\n" NOR);
                return 1;
        }
   else { 
                me->improve_skill("qianzhu-wandushou", 5000000);
                me->improve_skill("poison", 5000000);
                me->set("can_perform/qianzhu-wandushou/zhugu", 1);
                tell_object(me, HIC "��ѧ���ˡ�������졹��һ�С�\n" NOR);
                write(HIW "\n����ϸ�ж�ǧ��������ܸ���������������������������ڡ�\n" NOR);
                return 1;
        }
}