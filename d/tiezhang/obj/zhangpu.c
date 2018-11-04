#include <ansi.h> 

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");      
}

void create()
{
        set_name(WHT "��������" NOR , ({ "tiezhang zhangpu", "zhangpu", "pu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ҳ������飬ֽ�ʷ��ƣ���Ե��Ҳ�Ѳ�ȱ��ȫ�ˡ�\n");
                set("value", 1000);
                set("material", "paper");
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int level; 
        int neili_lost;

        if ( ! id(arg))
        return 0;

        if (where->query("pigging"))
        {
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }

        if (me->is_busy())
        {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() )
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if ( ! id(arg))
        { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( ! me->query_skill("literate", 1) )
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if( (int)me->query("jing") < 30 )
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if( me->query_skill("tie-zhang", 1) > 120)
        {
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ���ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        if( me->query_skill("tie-zhang", 1) < 50)
        {
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫����ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        if ( me->query_skill("tie-zhang", 1) > 100)
                neili_lost = 30;

   else if ( me->query_skill("tie-zhang", 1) > 60)
                neili_lost = 20;
      else
                neili_lost = 10;


        if( (int)me->query("neili") < neili_lost)
        {
                write("�������������޷�������ô������书��\n");
                return 1;
        }

        level = me->query_skill("tie-zhang", 1);
        if( (int)me->query("combat_exp") < (int) level * level * level / 10 )
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        switch(random(3))
        {
          case 0:
                message("vision", me->name() + "����һ�����ڶ���\n", environment(me), me);
                break;
          case 1:
                message("vision", me->name() + "һ�߶��飬�������һ�߷��������Ĵ��졣\n", environment(me), me);
                break;
          case 2:
                message("vision", me->name() + "����ɫʱ��ʱ�࣬���粻����\n", environment(me), me);
                break;
        }

        me->receive_damage("jing", 25);
        me->set("neili", (int)me->query("neili")-neili_lost);

        me->improve_skill("tie-zhang", (int)me->query("int") + 10);
        write("���ж����������ס��������ĵá�\n");
        return 1;
}

