#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIR "TEST" NOR, ({ "test" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
        object ob;
        seteuid(geteuid());
        add_action("do_full1", "full1");
        add_action("do_full2", "full2");
}

int do_full1(string str)
{
      int max;
      object me;

      if (! geteuid())
            seteuid (getuid());

      if (! str)
            me = this_player();

      else
            me = find_player(str);

      if (! me)
            return notify_fail ("û�������ҡ�\n");

      me->add("combat_exp", 100000);
      me->add("potential", 100000);
      me->add("experience", 5000);
      me->save();
      return 1;
}

int do_full2(string str)
{
      int max;
      object me;

      if (! geteuid())
            seteuid (getuid());

      if (! str)
            me = this_player();

      else
            me = find_player(str);

      if (! me)
            return notify_fail ("û�������ҡ�\n");

      me->add("combat_exp", 50000);
      me->add("potential", 50000);
      me->add("experience", 5000);
      me->save();
      return 1;
}

