#include <ansi.h>

void init()
{
        int i;
        object ob, me = this_player();

        if (! me || environment(me) != this_object())
                return 0;

        if (userp(me) && ! present("e lang", this_object()))
        {
                message("vision", HIR "\nͻȻ�䣬ֻ��������Ӱ������"
                                  "�˹�����\n" NOR, this_object());

	        for (i = 0; i < 5; i++)
        	{
	                ob = new("clone/quarry/lang2");
        	        ob->move(this_object());
                	ob->kill_ob(me);
        	}
        }
}

int valid_leave(object me, string dir)
{
        object ob = present("e lang", environment(me));

        if (ob && living(ob))
                return notify_fail(HIR "\n��ʱֻ���������Ƿ���һ������"
                                   "ס�����ȥ·��\n" NOR);

        return 1;
}
