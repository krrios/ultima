////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_SHAPE_HPP
#define SFML_SHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief A convex, colored polygon with an optional outline
///
////////////////////////////////////////////////////////////
class SFML_API Shape : public Drawable
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Creates an empty shape (no point).
    ///
    ////////////////////////////////////////////////////////////
    Shape();

    ////////////////////////////////////////////////////////////
    /// \brief Add a new point to the shape
    ///
    /// The new point is inserted at the end of the shape.
    ///
    /// \param x            X position of the point
    /// \param y            Y position of the point
    /// \param color        Color of the point
    /// \param outlineColor Outline color of the point
    ///
    ////////////////////////////////////////////////////////////
    void AddPoint(float x, float y, const Color& color = Color(255, 255, 255), const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Add a new point to the shape
    ///
    /// The new point is inserted at the end of the shape.
    ///
    /// \param position     Position of the point
    /// \param color        Color of the point
    /// \param outlineColor Outline color of the point
    ///
    ////////////////////////////////////////////////////////////
    void AddPoint(const Vector2f& position, const Color& color = Color(255, 255, 255), const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points composing the shape
    ///
    /// \param Total number of points
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetPointsCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable the shape's filling
    ///
    /// This option is enabled by default.
    ///
    /// \param enable True to enable, false to disable
    ///
    /// \see EnableOutline
    ///
    ////////////////////////////////////////////////////////////
    void EnableFill(bool enable);

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable the shape's outline
    ///
    /// This option is enabled by default.
    ///
    /// \param enable True to enable, false to disable
    ///
    /// \see EnableFill
    ///
    ////////////////////////////////////////////////////////////
    void EnableOutline(bool enable);

    ////////////////////////////////////////////////////////////
    /// \brief Change the position of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index    Index of the point
    /// \param position New position of the point
    ///
    /// \see GetPointPosition, SetPointColor, SetPointOutlineColor
    ///
    ////////////////////////////////////////////////////////////
    void SetPointPosition(unsigned int index, const Vector2f& position);

    ////////////////////////////////////////////////////////////
    /// \brief Change the position of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index Index of the point
    /// \param x     New X coordinate of the point
    /// \param y     New Y coordinate of the point
    ///
    /// \see GetPointPosition, SetPointColor, SetPointOutlineColor
    ///
    ////////////////////////////////////////////////////////////
    void SetPointPosition(unsigned int index, float x, float y);

    ////////////////////////////////////////////////////////////
    /// \brief Change the color of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index Index of the point
    /// \param color New color of the point
    ///
    /// \see GetPointColor, SetPointPosition, SetPointOutlineColor
    ///
    ////////////////////////////////////////////////////////////
    void SetPointColor(unsigned int index, const Color& color);

    ////////////////////////////////////////////////////////////
    /// \brief Change the outline color of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index Index of the point
    /// \param color New outline color of the point
    ///
    /// \see GetPointOutlineColor, SetPointPosition, SetPointColor
    ///
    ////////////////////////////////////////////////////////////
    void SetPointOutlineColor(unsigned int index, const Color& color);

    ////////////////////////////////////////////////////////////
    /// \brief Change the thickness of the shape outline
    ///
    /// \param width New width of the outline
    ///
    /// \see GetOutlineWidth, EnableOutline
    ///
    ////////////////////////////////////////////////////////////
    void SetOutlineWidth(float width);

    ////////////////////////////////////////////////////////////
    /// \brief Get the position of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index Index of the point
    ///
    /// \return Position of the index-th point
    ///
    /// \see SetPointPosition, GetPointColor, GetPointOutlineColor
    ///
    ////////////////////////////////////////////////////////////
    const Vector2f& GetPointPosition(unsigned int index) const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the color of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param Index index of the point
    ///
    /// \return Color of the index-th point
    ///
    /// \see SetPointColor, GetPointPosition, GetPointOutlineColor
    ///
    ////////////////////////////////////////////////////////////
    const Color& GetPointColor(unsigned int index) const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the outline color of a point
    ///
    /// Warning: this function doesn't check the validity of
    /// \a index, if it is out of bounds (ie. in the range
    /// [0, GetPointscount() - 1]) the behaviour is undefined.
    ///
    /// \param index Index of the point
    ///
    /// \return Outline color of the index-th point
    ///
    /// \see SetPointOutlineColor, GetPointPosition, GetPointColor
    ///
    ////////////////////////////////////////////////////////////
    const Color& GetPointOutlineColor(unsigned int index) const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the thickness of the shape outline
    ///
    /// \return Current outline width
    ///
    /// \see SetOutlineWidth
    ///
    ////////////////////////////////////////////////////////////
    float GetOutlineWidth() const;

    ////////////////////////////////////////////////////////////
    /// \brief Create a new line
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::Shape line = sf::Shape::Line(0, 0, 10, 20, 2.5f, sf::Color::Green);
    /// \endcode
    ///
    /// \param x0           X coordinate of the start point
    /// \param y0           Y coordinate of the start point
    /// \param x1           X coordinate of the end point
    /// \param y1           Y coordinate of the end point
    /// \param thickness    Thickness of the line
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Rectangle, Circle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Line(float p1x, float p1y, float p2x, float p2y, float thickness, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Create a new line
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::Vector2f start(0, 0);
    /// sf::Vector2f end(10, 20);
    /// sf::Shape line = sf::Shape::Line(start, end, 2.5f, sf::Color::Green);
    /// \endcode
    ///
    /// \param start        Start point
    /// \param end          End point
    /// \param thickness    Thickness of the line
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Rectangle, Circle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Line(const Vector2f& start, const Vector2f& end, float thickness, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Create a new rectangular shape
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::Shape rect = sf::Shape::Rectangle(10, 20, 50, 100, sf::Color::Red);
    /// \endcode
    ///
    /// \param left         Left coordinate of the rectangle
    /// \param top          Top coordinate of the rectangle
    /// \param width        Width of the rectangle
    /// \param height       Height of the rectangle
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Line, Circle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Rectangle(float left, float top, float width, float height, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Create a new rectangular shape
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::FloatRect source(10, 20, 50, 100);
    /// sf::Shape rect = sf::Shape::Rectangle(source, sf::Color::Red);
    /// \endcode
    ///
    /// \param rectangle    Rectangle defining the shape
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Line, Circle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Rectangle(const FloatRect& rectangle, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Create a new circular shape
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::Shape circle = sf::Shape::Circle(0, 0, 7, sf::Color::Blue);
    /// \endcode
    ///
    /// \param x            X coordinate of the center
    /// \param y            Y coordinate of the center
    /// \param radius       Radius of the circle
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Line, Rectangle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Circle(float x, float y, float radius, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

    ////////////////////////////////////////////////////////////
    /// \brief Create a new circular shape
    ///
    /// This is a static function that returns a new object,
    /// don't try to call it on an existing object to modify it.
    /// \code
    /// sf::Vector2f center(0, 0);
    /// sf::Shape circle = sf::Shape::Circle(center, 7, sf::Color::Blue);
    /// \endcode
    ///
    /// \param center       Center of the circle
    /// \param radius       Radius of the circle
    /// \param color        Color of the shape's points
    /// \param outline      Outline width
    /// \param outlineColor Outline color of the shape's points
    ///
    /// \see Line, Rectangle
    ///
    ////////////////////////////////////////////////////////////
    static Shape Circle(const Vector2f& center, float radius, const Color& color, float outline = 0.f, const Color& outlineColor = Color(0, 0, 0));

protected :

    ////////////////////////////////////////////////////////////
    /// \brief Draw the object to a render target
    ///
    /// \param target   Render target
    /// \param renderer Renderer providing low-level rendering commands
    ///
    ////////////////////////////////////////////////////////////
    virtual void Render(RenderTarget& target, Renderer& renderer) const;

private :

    ////////////////////////////////////////////////////////////
    /// \brief Compile the shape
    ///
    /// This function precomputes all the internal parameters
    /// needed to properly render the shape (center, outline points).
    ///
    ////////////////////////////////////////////////////////////
    void Compile();

    ////////////////////////////////////////////////////////////
    /// \brief Compute the normal of a given 2D segment
    ///
    /// \param p1     First point of the segment
    /// \param p2     Second point of the segment
    /// \param normal Variable to fill with the calculated normal
    ///
    /// \return False if the normal couldn't be calculated (segment is null)
    ///
    ////////////////////////////////////////////////////////////
    static bool ComputeNormal(const Vector2f& p1, const Vector2f& p2, Vector2f& normal);

    ////////////////////////////////////////////////////////////
    /// \brief Define a simple 2D point with position, normal and colors
    ///
    ////////////////////////////////////////////////////////////
    struct Point
    {
        Point(const Vector2f& position = Vector2f(0, 0), const Color& color = Color(255, 255, 255), const Color& outlineColor = Color(255, 255, 255));

        Vector2f Position;   ///< Position
        Vector2f Normal;     ///< Extruded normal
        Color    Col;        ///< Color of the point
        Color    OutlineCol; ///< Outline color of the point
    };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::vector<Point> myPoints;           ///< Points composing the shape
    float              myOutline;          ///< Outline width
    bool               myIsFillEnabled;    ///< Should we draw the inside if the shape ?
    bool               myIsOutlineEnabled; ///< Should we draw the outline if the shape ?
    bool               myIsCompiled;       ///< Compiled state of the shape
};

} // namespace sf


#endif // SFML_SHAPE_HPP
