#include <ansi.h>
inherit ITEM;

void setup()
{}
void create()
{
      set_name(YEL "������" NOR, ({"book"}));
      set("unit", "��");
      set("long", "һ�������˼����������ᡣ\n");
      set("value", 0);
      set_weight(200);
        
      setup();
}
