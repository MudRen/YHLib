#include <ansi.h>
inherit ROOM;

string look_wall();
string look_net();

void create()
{
        set("short","ܽ�ض�");
        set("long",@LONG
һ���붴�У����������ͷ���ϣ���Ŀһ����ԭ��������
һ��С����������Ǵ���������ģ�һ�����ܣ����ﳤ����ܽ
�ػ��������������С��(dong)��ʹ��Щ�������ڿ���Ҳ�г�
����������䡣��Զ��ʯ��(wall)�ϲ�����֩��������������
�������Ѿ��ܾ�û�����ˡ��뵽���ﲻ������֮����𣺡�ܽ
�ػ���ʱ���������˹项��
LONG);
   
        set("exits",([
                "out" : __DIR__"furong",
        ]));	

        set("item_desc",([
	        "wall"  : (: look_wall :),
	        "net"   : (: look_net :),

                "dong"  : HIY "����Ӷ�������������ܹ�ʯ(stone)ͻ�����ƺ���"
                          "�Դ�������(climb)��ȥ��\n" NOR,

                "stone" : "ֻ����Щͻʯ�еļ����絶���еĲ�����ݣ��������졣\n"
        ]));

        setup();
}	

void init()
{       
        add_action("do_pull", "pull");
        add_action("do_think", "think");
        add_action("do_climb", "climb");
}

int do_pull(string arg)
{
        object here;
 
        if (! here = find_object(__DIR__"furong1"))
                here = load_object(__DIR__"furong1");

       	if (! arg || arg != "net")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        if (here->query_temp("marks/��"))
        {
                write("֩�����Ѿ��������ˡ�\n");
                return 1;	
        }
    
        write(HIC "\n���֩��������������\n" NOR);
        here->set_temp("marks/��", 1);

        return 1;
}

int do_think(string arg)
{
        object here, me = this_player();
        int add;

        if (! here = find_object(__DIR__"furong1"))
                here = load_object(__DIR__"furong1");

        if (me->query("special_skill/clever"))
		add = me->query_int() * 4;
        else
		add = me->query_int() * 3;

        if (! here->query_temp("marks/��"))
                return notify_fail("ʲô��\n");

        if (! living(me) || arg != "wall")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("sword", 1) < 30)
                return notify_fail("��Ļ���������򲻹����޷�����ʯ��"
                                   "�ϵĽ�����\n");

        if ((int)me->query_skill("furong-jian", 1) < 20)
                return notify_fail("�㷢��ǽ�������صĽ���������£���"
                                   "��һʱ������ᡣ\n");

        if ((int)me->query_skill("furong-jian", 1) > 120)
                return notify_fail("�㷢��ǽ�������صĽ������ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 25)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 20);

        if (me->can_improve_skill("furong-jian"))
                me->improve_skill("furong-jian", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������صĽ�����"
                       "��������\n" NOR, me);
        write(HIC "��ԡ�ܽ�ؽ����������µ�����\n" NOR);
        return 1;
}

string look_wall()
{
        object here, me = this_player();
        string msg;

        if (! here = find_object(__DIR__"furong1"))
                here = load_object(__DIR__"furong1");

        if (here->query_temp("marks/��"))
        {
        	message_sort(HIG "\n���ߵ�ʯ��ǰ��Ĩȥ�������������Ļ�"
                             "���������������̵ľ���һ�׽�������Щȫ����"
                             "�����������̣����ɼ������̻�֮�˹������"
                             "�������ࡣ�㲻������λǰ����������֮�顣ֻ"
                             "������ȫ��һ����С�ˣ�ÿ���˶�ʹ����ͬ����"
                             "ʽ���������������۷���\n" NOR, me);

		write(WHT @TEXT

  ������������������������������������������������������������
  ��                                                 ****** ��
  ��   ��>        ��       ��        ��       ��     * ܽ * ��
  ��   \ __    ��v|\     \//>��    \//\__   ��v|^    * �� * ��
  ��   /<        /<       /> 	    />        /<     * �� * ��
  ��						     * �� * ��
  ��					             ****** ��
  ������������������������������������������������������������
							     
TEXT NOR);
	        return "\n";
         }

	 msg = WHT "\nʯ�����沼����֩����(net)����Ȼ�ܾ�û������������"
               "�ˡ�\n�����˴��������б���֮�����\n" NOR;

         return msg;
}

string look_net()
{
	object me = this_player();
        object here;
        string msg;

        if (! here = find_object(__DIR__"furong1"))
                here = load_object(__DIR__"furong1");

        if (here->query_temp("marks/��"))
                return "һ�ű����Ƶ�֩�������ڰ�ա�\n";

        msg = WHT "\n���߽�ϸ����ʯ���ϼ�ֻ֩�뻹�ڲ�ͣ����˿֯����͸��"
              "����\n������Լ����ʯ���ϲ�����һЩ���֡��㲻��������(pul"
              "l)��\n������������\n" NOR;

        return  msg;
}

int do_climb(string arg)
{	
	object me = this_player();

  	if (! arg || arg != "stone")
		return notify_fail("������ʲô��\n");

	write(HIG "\n����Ŷ���ͻ����ʯͷ�ϣ��ܿ������˶��ڡ�\n\n" NOR);

	me->move(__DIR__"furongfeng");
	   
	return 1;
}
